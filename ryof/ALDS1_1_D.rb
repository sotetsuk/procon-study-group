#! /usr/bin/env ruby
arr = []
n = STDIN.gets.chomp.to_i
n.times do
    arr << STDIN.gets.chomp.to_i
end
max = -100000000000000000
min = arr.shift
arr.each do |v|
    max = [max, v-min].max
    min = [min, v].min
end
STDOUT.puts max
