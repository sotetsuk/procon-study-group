#! /usr/bin/env ruby
n = STDIN.gets.chomp.to_i
arr = []
n.times do
	input = STDIN.gets.chomp.split(' ')
	case input[0]
	when 'insert'
		arr.unshift input[1]
	when 'delete'
		i = arr.index(input[1])
		arr.delete_at(i) unless i.nil?
	when 'deleteFirst'
		arr.shift
	when 'deleteLast'
		arr.pop
	end
end
STDOUT.puts arr.join(' ')
