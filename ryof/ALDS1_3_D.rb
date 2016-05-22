#! /usr/bin/env ruby
input = STDIN.gets.chomp
s1 = []
s2 = []
area_sum = 0
input.each_char.with_index do |ch, i|
	case ch
	when '\\'
		s1.push i
	when '/'
		left_edge = s1.pop
		next if left_edge == nil
		area = i - left_edge
		while s2.size > 0 && left_edge < s2.last[0] do
			area += s2.pop[1]
		end
		s2.push [left_edge, area]
	end
end
STDOUT.puts s2.map { |e| e[1] }.inject(0, :+)
STDOUT.puts s2.map { |e| e[1] }.unshift(s2.size).join(' ')
