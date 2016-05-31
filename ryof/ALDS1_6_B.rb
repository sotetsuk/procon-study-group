#!/usr/bin/env ruby
gets
a = gets.split.map(&:to_i)
i = -1
for j in 0..a.size-2 do
  if a[j] <= a[-1]
    i += 1
    a[i], a[j] = a[j], a[i]
  end
end
a[i+1], a[-1] = "[#{a[-1]}]", a[i+1]
puts a.join(' ')
