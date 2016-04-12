#! /usr/bin/env ruby
n = STDIN.gets.chomp.to_i
arr = STDIN.gets.chomp.split(' ').map {|e| e.to_i}
swap_cnt = 0
for i in 0..n-1 do
	minj = i
	for j in i..n-1 do
		if arr[j] < arr[minj] then
			minj = j
		end
	end
	if minj != i then
		arr[i], arr[minj] = arr[minj], arr[i]
		swap_cnt += 1
	end
end
puts arr.join(' ')
puts swap_cnt
