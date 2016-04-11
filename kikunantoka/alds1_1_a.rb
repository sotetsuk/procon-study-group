n = gets.to_i
array = gets.chomp.split(' ').map(&:to_i)
puts array.join(' ')
for i in 1..(n-1) do
  v = array[i]
  j = i - 1
  while j >= 0 && array[j] > v
    array[j+1] = array[j]
    j -= 1
    array[j+1] = v
  end
  puts array.join(' ')
end
