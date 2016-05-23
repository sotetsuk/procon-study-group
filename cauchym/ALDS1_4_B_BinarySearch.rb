n = gets.to_i
base = gets.chomp.split(" ").map(&:to_i)
m = gets.to_i
compare = gets.chomp.split(" ").map(&:to_i)
count = 0

compare.each do |i|
  left = 0
  right = base.size
  # right = n-1ならダメなのなんでだろう
  puts base[n]
  if base[n-1] >= i then
    while left + 1 < right
      mid = ((left+right)/2).floor
      if i == base[mid] then
        count += 1
        break
      elsif i < base[mid] then
        right = mid
      else
        left = mid
      end
    end
  end
end

puts count
# http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1817194#1
