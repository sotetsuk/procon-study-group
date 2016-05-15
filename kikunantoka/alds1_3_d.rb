input = gets.to_s
s1 = []
s2 = []
(input.length).times do |i|
  area = 0
  case input[i]
  when '\\'
    s1.push(i)
  when '/'
    next if s1.empty?
    left = s1.pop
    area += i - left
    while !s2.empty? && left < s2.last.first do
      area += s2.pop.last
    end
    s2.push([left, area])
  end
end
line1 = 0
line2 = s2.length.to_s
(s2.length).times do |i|
  line1 += s2[i].last
  line2 += ' ' + s2[i].last.to_s
end
puts line1
puts line2
