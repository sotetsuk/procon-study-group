a = gets.chomp.split(' ').map(&:to_s)
s = []
ans = 0
(a.size).times do |i|
  if a[i] =~ /\d+/
    s.push(a[i].to_i)
  else
    tmp = s.pop(2)
    res =
      a[i] == '+' ? tmp[0] + tmp[1] :
      a[i] == '-' ? tmp[0] - tmp[1] :
      tmp[0] * tmp[1]
    s.push(res)
  end
end
puts s.pop
