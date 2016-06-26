n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)
t = []
n.times do |i|
  t << arr.shift
end

# swapメソッド
def swap(list, idx1, idx2)
  list[idx1], list[idx2] = list[idx2], list[idx1]
  return list
end

def minCostPath(list)
  sorted = list.sort
  total = 0
  
  # list分回す
  list.size.times do |i|
    # ソート済みのリストから順番に取ってくる
    idx1 =sorted[i]
   
    # 未ソートのリストから対象の値のindexを取ってくる
    idx2 = list.index idx1
    n = 0 
    while idx2 > i
      # 巡回群の長さ
      n += 1
      
      # 巡回群の最小コストを求めるためのスワップコストを出す
      sortedidx = list.index sorted[idx2]
      total += list[sortedidx]
      list = swap(list, idx2, sortedidx) 

      # 次の経路のためにidxを変える
      idx2 = sortedidx
    end
    total += [idx1 * n, idx1*2+sorted[0]*(n+2)].min
  end
  return total
end

total = minCostPath(t)
p total
