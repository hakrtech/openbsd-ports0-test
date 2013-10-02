# ex:ts=8 sw=4:
# $openbsd: reporter.pm,v 1.20 2013/09/30 19:08:35 espie exp $
#
# copyright (c) 2010 marc espie <espie@openbsd.org>
#
# permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# the software is provided "as is" and the author disclaims all warranties
# with regard to this software including all implied warranties of
# merchantability and fitness. in no event shall the author be liable for
# any special, direct, indirect, or consequential damages or any damages
# whatsoever resulting from loss of use, data or profits, whether in an
# action of contract, negligence or other tortious action, arising out of
# or in connection with the use or performance of this software.
use strict;
use warnings;

package DPB::MiniCurses;
use Term::Cap;

my $width;
my $wsz_format = 'SSSS';
our %sizeof;

sub find_window_size
{
	my $self = shift;
	# try to get exact window width
	my $r;
	$r = pack($wsz_format, 0, 0, 0, 0);
	$sizeof{'struct winsize'} = 8;
	require 'sys/ttycom.ph';
	$width = 80;
	if (ioctl(STDOUT, &TIOCGWINSZ, $r)) {
		my ($rows, $cols, $xpix, $ypix) =
		    unpack($wsz_format, $r);
		$self->{width} = $cols;
		$self->{height} = $rows;
	}
}

sub term_send
{
	my ($self, $seq) = @_;
	$self->{terminal}->Tputs($seq, 1, \*STDOUT);
}

sub refresh
{
	my $self = shift;
	$self->{write} = 'go_write_home';
	$self->{force} = 1;
}

sub create_terminal
{
	my $self = shift;
	my $oldfh = select(STDOUT);
	$| = 1;
	# XXX go back to totally non-buffered raw shit
	binmode(STDOUT, ':pop');
	select($oldfh);
	use POSIX;
	my $termios = POSIX::Termios->new;
	$termios->getattr(0);
	$self->{terminal} = Term::Cap->Tgetent({ OSPEED =>
	    $termios->getospeed });
	$self->find_window_size;
	$self->{home} = $self->{terminal}->Tputs("ho", 1);
	$self->{clear} = $self->{terminal}->Tputs("cl", 1);
	$self->{down} = $self->{terminal}->Tputs("do", 1);
	$self->{glitch} = $self->{terminal}->Tputs("xn", 1);
	$self->{cleareol} = $self->{terminal}->Tputs("ce", 1);
	if ($self->{home}) {
		$self->{write} = "go_write_home";
	} else {
		$self->{write} = "write_clear";
	}
}

sub write_clear
{
	my ($self, $msg) = @_;
	my $r = $self->{clear};
	$self->{oldlines} = [$self->cut_lines($msg)];
	my $n = 2;
	for my $line (@{$self->{oldlines}}) {
		last if $n++ > $self->{height};
		$r .= $self->clamped($line);
	}
	print $r;
}

sub cut_lines
{
	my ($self, $msg) = @_;
	my @lines = ();
	for my $line (split("\n", $msg)) {
		while (length $line > $self->{width}) {
			push(@lines, substr($line, 0, $self->{width}));
			$line = substr($line, $self->{width});
		}
		push(@lines, $line);
	}
	return @lines;
}

sub clamped
{
	my ($self, $line) = @_;
	if (!$self->{glitch} && length $line == $self->{width}) {
		return $line;
	} else {
		return $line."\n";
	}
}

sub clear_clamped
{
	my ($self, $line) = @_;
	if (!$self->{glitch} && length $line == $self->{width}) {
		return $line;
	} else {
		return $self->{cleareol}.$line."\n";
	}
}

sub do_line
{
	my ($self, $new, $old) = @_;
	# line didn't change: try to go down
	if (defined $old && $old eq $new) {
		if ($self->{down}) {
			return $self->{down};
		}
	}
	# adjust newline to correct length
	if (defined $old && (length $old) > (length $new)) {
		if ($self->{cleareol}) {
			return $self->clear_clamped($new);
		}
		$new .= " "x ((length $old) - (length $new));
	}
	return $self->clamped($new);
}

sub lines
{
	my ($self, @new) = @_;

	my $n = 2;
	my $r = '';

	while (@new > 0) {
		return $r if $n++ > $self->{height};
		$r .= $self->do_line(shift @new, shift @{$self->{oldlines}});
	}
	# extra lines must disappear
	while (@{$self->{oldlines}} > 0) {
		my $line = shift @{$self->{oldlines}};
		if ($self->{cleareol}) {
			$r .= $self->clear_clamped('');
		} else {
			$line = " "x (length $line);
			$r .= $self->clamped($line);
		}
		last if $n++ > $self->{height};
	}
	return $r;
}

sub write_home
{
	my ($self, $msg) = @_;
	my @new = $self->cut_lines($msg);
	print $self->{home}.$self->lines(@new);
	$self->{oldlines} = \@new;
}

sub go_write_home
{
	# first report has to clear the screen
	my ($self, $msg) = @_;
	$self->write_clear($msg);
	$self->{write} = 'write_home';
}

1;
