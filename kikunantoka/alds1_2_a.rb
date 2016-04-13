n = gets.to_i
a = gets.chomp.split(' ').map(&:to_i)
num = 0
n.times do |i|
  (n-1).downto(i+1) do |j|
    if a[j] < a[j-1]
      a[j], a[j-1] = a[j-1], a[j]
      num += 1
    end
  end
end
puts a.join(' ')
puts num
