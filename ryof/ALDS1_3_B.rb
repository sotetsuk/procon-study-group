#! /usr/bin/env ruby
queue_info = STDIN.gets.chomp.split(' ').map {|e| e.to_i}
n = queue_info[0].to_i
q = queue_info[1].to_i
queue = []
n.times do
	process = STDIN.gets.chomp.split(' ')
	process[1] = process[1].to_i
	queue << process
end
elapsed_time = 0
while !queue.empty? do
	process = queue.shift
	if process[1] <= q
		elapsed_time += process[1]
		puts "#{process[0]} #{elapsed_time}"
		next
	else
		elapsed_time += q
		process[1] -= q
		queue << process
	end
end
