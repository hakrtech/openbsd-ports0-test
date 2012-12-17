#!/usr/bin/env ruby
# Copyright (c) 2008-2012, Edd Barrett <vext01@gmail.com>
# 
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
# 
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
# 
# RBlatter
# $Id: tlpdbindex.rb,v 1.3 2012/12/17 20:28:04 edd Exp $
#
# Index a tlpdb file for faster lookups

class TlpdbIndex

	attr_reader :index

	# Make a new index based upon the tlpdb file '+file+'.
	# * +file+ is a the tlpdb
	def initialize(file)
		@index = {}	
		@dbFile = file
		makeIndex
	end

	# Print debug info about this index database
	def dumpIndex()
		@index.each do | key, val |
			puts "#{key} : #{val}"
		end
	end

	private
	# Parse and index the tlpdb file
	def makeIndex()

		if !$QUIET then
			puts "Indexing TlpDB..."
		end

		lineno = 1
		for line in @dbFile do
			if line =~ /^name (.*)/ then
				@index[$1] = lineno
			end
			lineno = lineno.next
		end

		if !$QUIET then
			puts "Done. #{@index.size} packages"
		end
	end
end
