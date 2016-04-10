n = gets.to_i
min = 10 ** 10
maxv = -10 ** 10
n.times do
  input = gets.to_i
  maxv = maxv > input - min ? maxv : input - min
  min = input < min ? input : min
end
puts(maxv)
