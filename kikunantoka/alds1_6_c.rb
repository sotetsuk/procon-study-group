def partition(a, p, r)
  unused, x = a[r].split(' ')
  i = p - 1
  p.upto(r-1) do |j|
    unused, aj = a[j].split(' ')
    if aj.to_i <= x.to_i
      i = i + 1
      a[i], a[j] = a[j], a[i]
    end
  end
  a[i+1], a[r] = a[r], a[i+1]
  return i + 1
end

def quickSort(a, p, r)
  if p < r
    q = partition(a, p, r)
    quickSort(a, p, q-1)
    quickSort(a, q+1, r)
  end
end

def checkStable(origin, sorted)
  originOrder = {}
  sortedOrder = {}
  (origin.size).times do |i|
    alphabet, num = origin[i].split(' ')
    originOrder[num.to_i] = originOrder[num.to_i] == nil ? alphabet.to_s : originOrder[num.to_i] + alphabet.to_s
    alphabet, num = sorted[i].split(' ')
    sortedOrder[num.to_i] = sortedOrder[num.to_i] == nil ? alphabet.to_s : sortedOrder[num.to_i] + alphabet.to_s
  end
  return originOrder == sortedOrder ? 'Stable' : 'Not stable'
end

a = []
n = gets.to_i
n.times do
  a.push(gets.to_s)
end
origin = Marshal.load(Marshal.dump(a))
quickSort(a, 0, a.size-1)
puts checkStable(origin, a)
puts a
