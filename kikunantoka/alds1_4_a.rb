def linerSearch(array, key)
  i = 0
  array.push(key)
  while array[i] != key
    i += 1
    if i == array.length - 1
      array.pop
      return false
    end
  end
  array.pop
  return true
end

n = gets.to_i
s = gets.chomp.split(' ').map(&:to_i)
q = gets.to_i
t = gets.chomp.split(' ').map(&:to_i)
count = 0

q.times do |i|
  count += 1 if linerSearch(s, t[i])
end
puts count
