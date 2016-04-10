n = gets.chomp.to_i
l = []
n.times do |num|
  l << gets.chomp.to_i
end

m = 100000000000
d = -100000000000
l.each do |i|
  n = i.to_i
  a = n - m 
  d = a if a > d
  m = n if m > n 
end
p d
