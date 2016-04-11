n = STDIN.gets.to_i
array = STDIN.gets.split.map(&:to_i)
counter = 0
flag = false
for i in 0..(n-1) do
  minj = i
  flag = false
  for j in i..(n-1) do
    if array[j] < array[minj]
      minj = j
      flag = true
    end
  end
  tmp = array[i]
  array[i] = array[minj]
  array[minj] = tmp
  if flag then
    counter += 1
  end
end

puts array.join(' ')
puts counter
