#! /usr/bin/env ruby
arr = []
STDIN.gets.chomp.split(' ').each do |e|
	case e
	when '+' then
		a = arr.pop
		b = arr.pop
		arr.push a + b
	when '-' then
		a = arr.pop
		b = arr.pop
		arr.push b - a
	when '*' then
		a = arr.pop
		b = arr.pop
		arr.push a * b
	else
		arr.push e.to_i
	end
end
STDOUT.puts arr.pop
