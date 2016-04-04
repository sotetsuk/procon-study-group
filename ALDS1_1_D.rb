lines = gets.rstrip.split(/\r?\n/).map(&:to_i)
result = 0
min = lines[0]
for i in lines do
  diff = [diff, lines[i]-min ].max
  min = [min, lines[i]].min
end
p result

