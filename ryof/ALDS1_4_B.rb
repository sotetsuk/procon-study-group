#! /usr/bin/env ruby
n = STDIN.gets.chomp.to_i
s = STDIN.gets.chomp.split(' ').map { |e| e.to_i }
q = STDIN.gets.chomp.to_i
t = STDIN.gets.chomp.split(' ').map { |e| e.to_i }
sum = 0
t.each do |te|
	r = n
	l = 0
	while l < r do
		m = (l + r) / 2
		if s[m] == te
			sum += 1
			break
		elsif te < s[m]
			r = m
		else
			l = m + 1
		end
	end
end
STDOUT.puts sum
