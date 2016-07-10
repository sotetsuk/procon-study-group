def solve(i, m, a, n)
  return true if m == 0
  return false if i >= n
  res = solve(i+1, m, a, n) || solve(i+1, m - a[i], a, n)
  return res
end

n = gets.to_i
a = gets.chomp.split(' ').map(&:to_i)
q = gets.to_i
m = gets.chomp.split(' ').map(&:to_i)

q.times do |i|
  puts solve(0, m[i], a.select{|j| j <= m[i]}, a.select{|j| j <= m[i]}.size) ? 'yes' : 'no'
end
