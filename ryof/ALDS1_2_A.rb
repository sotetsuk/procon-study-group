#! /usr/bin/env ruby
n = STDIN.gets.chomp.to_i
arr = STDIN.gets.chomp.split(' ').map {|e| e.to_i}
swap_cnt = 0
loopout = true
for i in 0..n-1 do
	(n-1).downto(i+1) do |j|
		if arr[j] < arr[j-1] then
			tmp = arr[j]
			arr[j] = arr[j-1]
			arr[j-1] = tmp
			swap_cnt += 1
			loopout = false
		end
	end
	break if loopout
end
puts arr.join(' ')
puts swap_cnt
