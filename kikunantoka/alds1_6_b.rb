def partition(a, p, r)
  x = a[r]
  i = p - 1
  p.upto(r-1) do |j|
    if a[j] <= x
      i = i + 1
      a[i], a[j] = a[j], a[i]
    end
  end
  a[i+1], a[r] = a[r], a[i+1]
  return i + 1
end

n = gets.to_i
a = gets.chomp.split(' ').map(&:to_i)
index = partition(a, 0, a.size-1)
a[index] = '[' + a[index].to_s + ']'
puts a.join(' ')
