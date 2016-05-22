def binarySearch(array, key, n)
  left = 0
  right = n
  while left < right
    mid = (left + right) / 2
    if array[mid] == key
      return true
    elsif key < array[mid]
      right = mid
    else
      left = mid + 1
    end
  end
  return false
end

n = gets.to_i
s = gets.chomp.split(' ').map(&:to_i)
q = gets.to_i
t = gets.chomp.split(' ').map(&:to_i)
count = 0

q.times do |i|
  count += 1 if binarySearch(s, t[i], n)
end
puts count
