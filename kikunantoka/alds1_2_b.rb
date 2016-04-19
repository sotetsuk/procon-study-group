def selectionSort(a, n)
  count = 0
  n.times do |i|
    minj = i
    i.upto(n-1) do |j|
      minj = j if a[j] < a[minj]
    end
    if i != minj
      a[i], a[minj] = a[minj], a[i]
      count += 1
    end
  end
  return count
end

n = gets.to_i
a = gets.chomp.split(' ').map(&:to_i)
count = selectionSort(a, n)
puts a.join(' ')
puts count
