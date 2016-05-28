#! /usr/bin/env ruby
n = STDIN.gets.chomp.to_i
s = STDIN.gets.chomp.split(' ').map { |e| e.to_i }
q = STDIN.gets.chomp.to_i
t = STDIN.gets.chomp.split(' ').map { |e| e.to_i }
sum = 0
t.each do |te|
	# sum += 1 if s.include?(te)
	s.each do |se|
		if se == te
			sum += 1
			break
		end
	end
end
STDOUT.puts sum
