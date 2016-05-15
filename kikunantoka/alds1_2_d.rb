def insertionSort(a, n, g, cnt)
  g.upto(n-1) do |i|
    v = a[i]
    j = i - g
    while j >= 0 && a[j] > v do
      a[j+g] = a[j]
      j = j - g
      cnt += 1
    end
    a[j+g] = v
  end
  return cnt
end

def shellSort(a, n)
  cnt = 0
  m = 0
  g = [1]
  while g[m] * 3 + 1 < n do
    g[m+1] = g[m] * 3 + 1
    m += 1
  end
  gStr = ''
  (m).downto(0) do |i|
    gStr << g[i].to_s
    gStr << ' '
    cnt = insertionSort(a, n, g[i], cnt)
  end
  puts m + 1
  puts gStr
  puts cnt
  n.times do |i|
    puts a[i]
  end
end

n = gets.to_i
a = []
n.times do
  a.push(gets.to_i)
end
shellSort(a, n)
