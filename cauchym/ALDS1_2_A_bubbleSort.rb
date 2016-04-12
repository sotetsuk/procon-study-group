n = STDIN.gets.to_i
array = STDIN.gets.split.map(&:to_i)
flag = 1
counter = 0
(array.length).downto(1){ |i|
  while flag == 1 do
    flag = 0
    (n-1).downto(1){ |j|
      if array[j] < array[j-1] then
        tmp = array[j]
        array[j] = array[j-1]
        array[j-1] = tmp
        flag = 1
        counter +=1
      end
    }
  end
}

puts array.join(' ')
puts counter
