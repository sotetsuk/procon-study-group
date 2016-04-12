#! /usr/bin/env ruby
def bubble_sort arr
	arr = arr.dup
	n = arr.size
	for i in 0..n-1 do
		(n-1).downto(i+1) do |j|
			arr[j], arr[j-1] = arr[j-1], arr[j] if arr[j][1] < arr[j-1][1]
		end
	end
	return arr
end
def selection_sort arr
	arr = arr.dup
	n = arr.size
	for i in 0..n-1 do
		minj = i
		for j in i..n-1 do
			minj = j if arr[j][1] < arr[minj][1]
		end
		arr[i], arr[minj] = arr[minj], arr[i]
	end
	return arr
end
n = STDIN.gets.chomp.to_i
arr = STDIN.gets.chomp.split(' ')
bs_arr = bubble_sort(arr)
puts bs_arr.join(' ')
puts 'Stable'
ss_arr = selection_sort(arr)
puts selection_sort(ss_arr).join(' ')
puts bs_arr == ss_arr ? 'Stable' : 'Not stable'
