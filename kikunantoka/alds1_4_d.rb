def check(baggage, k, p)
  while(1)
    index = 0
    k.times do
      tmp = 0
      while tmp + baggage[index] <= p
        tmp += baggage[index]
        index += 1
        return index if index == baggage.size
      end
    end
    return index
  end
end

baggage = []
n, k = gets.chomp.split(' ').map(&:to_i)
n.times do
  baggage.push(gets.to_i)
end
left = 0
right = 100000 * 100000
while (right - left) > 1
  mid = (left + right) / 2
  v = check(baggage, k, mid)
  if v >= n
    right = mid
  else
    left = mid
  end
end
puts right


# 線形探索はTLEが出る
#
# def calcLoad(baggage, k)
#   load = baggage.max
#   while(1)
#     index = 0
#     k.times do
#       tmp = 0
#       while index < baggage.size && tmp + baggage[index] <= load
#         tmp += baggage[index]
#         index += 1
#       end
#     end
#     return load if baggage.size <= index
#     load += 1
#   end
# end
#
# baggage = []
# n, k = gets.chomp.split(' ').map(&:to_i)
# n.times do
#   baggage.push(gets.to_i)
# end
# puts calcLoad(baggage, k)
