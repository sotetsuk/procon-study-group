#! /usr/bin/env ruby
n = STDIN.gets.chomp.to_i
a = STDIN.gets.chomp.split.map(&:to_i)
q = STDIN.gets.chomp.to_i
m = STDIN.gets.chomp.split.map(&:to_i)
sum = a.reduce(:+)
m.each{|mi|puts(mi<=sum&&((0..n).any?{|p|a.combination(p).any?{|c|c.reduce(:+)==mi}})?'yes':'no')}
