#! /usr/bin/env ruby
n = STDIN.gets.chomp.to_i
arr = STDIN.gets.chomp.split(' ').map {|e| e.to_i}
puts arr.join(' ')
for i in 1..n-1 do
	v = arr[i]
	j = i - 1
	while j >= 0 && arr[j] > v do
		arr[j+1] = arr[j]
		j -= 1
	end
	arr[j+1] = v
	puts arr.join(' ')
end
