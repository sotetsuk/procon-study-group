INF = 2000000000
@count = 0
def merge(a, left, mid, right)
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
    @count += 1
    if l[i] <= r[j]
      a[k] = l[i]
      i = i + 1
    else
      a[k] = r[j]
      j = j + 1
    end
  end
end

def mergeSort(a, left, right)
  if left + 1 < right
    mid = (left + right) / 2
    mergeSort(a, left, mid)
    mergeSort(a, mid, right)
    merge(a, left, mid, right)
  end
end

n = gets.to_i
a = gets.chomp.split(' ').map(&:to_i)
mergeSort(a, 0, a.size())
puts a.join(' ')
puts @count
