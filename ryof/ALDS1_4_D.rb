#! /usr/bin/env ruby
P = 1000000000
n, k = STDIN.gets.chomp.split.map{|e| e.to_i}
packs = []
n.times{|i| packs << STDIN.gets.chomp.to_i}
l, r = 0, P
loading_limit = -1
while l <= r do
	loading_limit = l + (r - l) / 2
	pack_loaded = 0
	current_load = 0
	tracks = 1
	packs.each do |pack|
		break if pack > loading_limit
		if current_load + pack > loading_limit
			current_load = 0
			tracks += 1
			break if tracks > k
		end
		pack_loaded += 1
		current_load += pack
	end
	break if l == r
	if pack_loaded < n
		l = loading_limit + 1
	else
		r = loading_limit
	end
end
puts loading_limit
