MAX_VAL = 10000

def countingSort(a, b, k, n)
  c = Array.new(k, 0)

  n.times do |i|
    c[a[i]] += 1
  end

  1.upto(k-1) do |i|
    c[i] = c[i] + c[i-1]
  end

  (n-1).downto(0) do |i|
    b[c[a[i]]-1] = a[i]
    c[a[i]] -= 1
  end

end

n = gets.to_i
a = gets.chomp.split(' ').map(&:to_i)
b = Marshal.load(Marshal.dump(a))
countingSort(a, b, MAX_VAL, n)
puts b.join(' ')
