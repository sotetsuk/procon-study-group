n, q = gets.chomp.split(' ').map(&:to_i)
array = []
n.times do |i|
  array[i] = gets.chomp.split(' ').map(&:to_s)
end
time = 0
while array.length != 0
  tmp = array.shift
  tmp[1] = tmp[1].to_i
  if tmp[1] <= q
    time += tmp[1]
    puts tmp[0] << ' ' << time.to_s
  else
    time += q
    tmp[1] -= q
    array.push(tmp)
  end
end
