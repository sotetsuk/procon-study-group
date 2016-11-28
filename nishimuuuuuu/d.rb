n = gets.chomp.to_i

se = []

n.times do 
  a = gets.chomp.split('-')
  if (0..4).include?(a[0][-1].to_i)
    a[0][-1] = '0'
  else
    a[0][-1] = '5'
  end

  if (1..4).include?(a[1][-1].to_i)
    a[1][-1] = '5'
  elsif (5..9).include?(a[1][-1].to_i)
    a[1][-1] = '0'
    if a[1][-2] == '5'
      a[1][-2] == '0'
      if a[1][-3] == '9'
        a[1][-3] = '0'
        a[1][-4] = (a[1][-4].to_i + 1).to_s
      else
        a[1][-3] = (a[1][-3].to_i + 1).to_s
      end
    else
      a[1][-2] = (a[1][-2].to_i + 1).to_s
    end
  end
  se << a
end

se = se.sort{|i,j| i[0] <=> j[0]}
res = []
se.each do |i|
  if res.empty?
    res << i
  else
    if res[-1][1] < i[0]
      res << i
    else
      res[-1][1] = [res[-1][1], i[1]].max
    end
  end
end


puts res.map{|i| i.join('-')}.join("\n")
