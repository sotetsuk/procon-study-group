#! /usr/bin/env ruby
def insertion_sort arr, n, g
	for i in g..n-1 do
		v = arr[i]
		j = i - g
		while j >= 0 && arr[j] > v do
			arr[j+g] = arr[j]
			j -= g
			$cnt += 1;
		end
		arr[j+g] = v
	end
	return arr
end

n = STDIN.gets.chomp.to_i
arr = []
n.times do
	arr << STDIN.gets.chomp.to_i
end
$cnt = 0
g = [1]
while true do
	gi = 3 * g.last + 1
	gi < n ? g << gi : break
end
puts g.size
puts g.reverse!.join(' ')
g.each do |gi|
	insertion_sort(arr, n, gi)
end
puts $cnt
arr.each do |elem|
	puts elem
end
