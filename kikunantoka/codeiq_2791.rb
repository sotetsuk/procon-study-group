n = gets.to_i
a = Array.new(n+2) {
  Array.new(n+2)
}
count = 0
n.times do |i|
  a[i+1] = gets.to_s
end
a[0] = a[n+1] = 'X' * (n+2)
(n).times do |i|
  a[i+1] = 'X' << a[i+1].chomp << 'X'
end

=begin

n*nの範囲内で
各スタート位置から3方向に探索...
を移動できなくなるまで繰り返し、
深さの最大値を求める

=end

# 確認用出力 TODO: 消す
puts '---'
(n+2).times do |i|
  puts a[i]
end
