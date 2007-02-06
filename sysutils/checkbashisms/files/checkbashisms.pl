#! /usr/bin/perl -w
# $Id: checkbashisms.pl,v 1.1.1.1 2007/02/06 22:22:16 jasper Exp $

#   Copyright (C) 2003 Julian Gilbey
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, you can find it on the World Wide
# Web at http://www.gnu.org/copyleft/gpl.html, or write to the Free
# Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
# MA 02111-1307, USA.

use strict;

(my $progname = $0) =~ s|.*/||;

my $usage = <<"EOF";
Usage: $progname script ...
   or: $progname --help
   or: $progname --version
This script performs basic checks for the presence of bashisms
in /bin/sh scripts.
EOF

my $version = <<"EOF";
This is $progname, from the Debian devscripts package, version 2.9.17
This code is copyright 2003 by Julian Gilbey <jdg\@debian.org>,
based on original code which is copyright 1998 by Richard Braakman
and copyright 2002 by Josip Rodin.
This program comes with ABSOLUTELY NO WARRANTY.
You are free to redistribute this code under the terms of the
GNU General Public License, version 2, or (at your option) any later version.
EOF

##
## handle command-line options
##
if (int(@ARGV) == 0 or $ARGV[0] =~ /^(--help|-h)$/) { print $usage; exit 0; }
if (@ARGV and $ARGV[0] =~ /^(--version|-v)$/) { print $version; exit 0; }


my $status = 0;

foreach my $filename (@ARGV) {
    unless (open C, "$filename") {
	warn "cannot open script $filename for reading: $!\n";
	$status |= 2;
	next;
    }

    my $cat_string = "";

    while (<C>) {
	if ($. == 1) { # This should be an interpreter line
	    if (m,^\#!\s*(\S+),) {
		my $interpreter = $1;
		if ($interpreter =~ m,/bash$,) {
		    warn "script $filename is already a bash script; skipping\n";
		    $status |= 2;
		    last;  # end this file
		}
		elsif ($interpreter !~ m,/(sh|ash|dash)$,) {
		    warn "script $filename does not appear to be a /bin/sh script; skipping\n";
		    $status |= 2;
		    last;
		}
	    } else {
		warn "script $filename does not appear to have a \#! interpreter line;\nyou may get strange results\n";
	    }
	}

	next if m,^\s*\#,;  # skip comment lines
	chomp;
	my $orig_line = $_;

	s/(?<!\\)\#.*$//;   # eat comments

	if (m/(?:^|\s+)cat\s*\<\<\s*(\w+)/) {
	    $cat_string = $1;
	}
	elsif ($cat_string ne "" and m/^$cat_string/) {
	    $cat_string = "";
	}
	my $within_another_shell = 0;
	if (m,(^|\s+)((/usr)?/bin/)?((b|d)?a|k|z|t?c)sh\s+-c\s*.+,) {
	    $within_another_shell = 1;
	}
	# if cat_string is set, we are in a HERE document and need not
	# check for things
	if ($cat_string eq "" and !$within_another_shell) {
	    my $found = 0;
	    my $match = '';
	    my $explanation = '';
	    my %bashisms = (
		'(?:^|\s+)function\s+\w+' =>   q<'function' is useless>,
		'(?:^|\s+)select\s+\w+' =>     q<'select' is not POSIX>,
		'(?:^|\s+)source\s+(?:\.\/|\/|\$)[^\s]+' =>
		                               q<should be '.', not 'source'>,
		'(\[|test|-o|-a)\s*[^\s]+\s+==\s' =>
		                               q<should be 'b = a'>,
		'\s\|\&' =>                    q<pipelining is not POSIX>,
		'\$\[\w+\]' =>                 q<arithmetic not allowed>,
		'\$\{\w+\:\d+(?::\d+)?\}' =>   q<${foo:3[:1]}>,
		'\$\{\w+(/.+?){1,2}\}' =>      q<${parm/?/pat[/str]}>,
		'[^\\\]\{([^\s]+?,)+[^\\\}\s]+\}' =>
		                               q<brace expansion>,
		'(?:^|\s+)\w+\[\d+\]=' =>      q<bash arrays, H[0]>,
		'\$\{\#?\w+\[[0-9\*\@]+\]\}' => q<bash arrays, ${name[0|*|@]}>,
		'(?:^|\s+)(read\s*(?:;|$))' => q<read without variable>,
		'\$\(\([A-Za-z]' => q<cnt=$((cnt + 1)) does not work in dash>,
		'echo\s+-[ne]' =>              q<echo -n/-e>,
		'exec\s+-[acl]' =>             q<exec -c/-l/-a name>,
		'\blet\s' =>                   q<let ...>,
		'\$RANDOM\b' =>                q<$RANDOM>,
		'(?<!\$)\(\(' =>               q<'((' should be '$(('>,
	    );

	    while (my ($re,$expl) = each %bashisms) {
		if (m/($re)/) {
		    $found = 1;
		    $match = $1;
		    $explanation = $expl;
		    last;
		}
	    }
	    # since this test is ugly, I have to do it by itself
	    # detect source (.) trying to pass args to the command it runs
	    if (not $found and m/^\s*(\.\s+[^\s]+\s+([^\s]+))/) {
		if ($2 eq '&&' || $2 eq '||') {
		    # everything is ok
		    ;
		} else {
		    $found = 1;
		    $match = $1;
		}
	    }
	    unless ($found == 0) {
		warn "possible bashism in $filename line $. ($explanation):\n$orig_line\n";
		$status |= 1;
	    }
	}
    }

    close C;
}

exit $status;
