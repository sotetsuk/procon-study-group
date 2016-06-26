INF = 2000000000
def merge(a, left, mid, right)
  cnt = 0
  n1 = mid - left
  n2 = right - mid
  l = []
  r = []
  (n1).times do |i|
    l[i] = a[left + i]
  end
  (n2).times do |i|
    r[i] = a[mid + i]
  end
  l[n1] = r[n2] = INF
  i = 0
  j = 0
  for k in left...right do
    if l[i] <= r[j]
      a[k] = l[i]
      i = i + 1
    else
      a[k] = r[j]
      j = j + 1
      cnt += n1 - i
    end
  end
  return cnt
end

def mergeSort(a, left, right)
  if left + 1 < right
    mid = (left + right) / 2
    v1 = mergeSort(a, left, mid)
    v2 = mergeSort(a, mid, right)
    v3 = merge(a, left, mid, right)
    return v1 + v2 + v3
  else
    return 0
  end
end

n = gets.to_i
a = gets.chomp.split(' ').map(&:to_i)
puts mergeSort(a, 0, a.size())
