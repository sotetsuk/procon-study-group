n = STDIN.gets.to_i
max = -1000000000
min = STDIN.gets.to_i
(2..n).each { |i|
  x = STDIN.gets.to_i
  if max < x - min then
    max = x - min
  end
  if x < min
    min = x
  end
}
puts max
