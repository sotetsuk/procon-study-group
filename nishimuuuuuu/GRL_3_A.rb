v, e = gets.chomp.split.map(&:to_i)
exit if e == 0
item = []
e.times do
  item << gets.chomp.split.map(&:to_i)
end

g = Array.new(v)
item.each do |elem|
  s = elem[0]
  t = elem[1]
  g[s] ||= []
  g[t] ||= []
  g[s] << t
  g[t] << s
end

g = g.map(&:uniq)

prenum = Array.new(v)
parent = Array.new(v) 
lowest = Array.new(v)



cnt = 0
def dfs(idx, prev, cnt, prenum, parent, lowest, g)
  prenum[idx] = lowest[idx] = cnt
  cnt += 1

  g[idx].each do |item|
    unless prenum[item].nil?
      unless item == prev
        lowest[idx] = [lowest[idx], prenum[item]].min
      end
      next
    end

    parent[item] = idx
    dfs(item, idx, cnt, prenum, parent, lowest, g)
    lowest[idx] = [lowest[idx], lowest[item]].min
  end
end

dfs(0, 1, cnt, prenum, parent, lowest, g)

res = Array.new(v, false)

# root check
res[0] = true if parent.count{|i| i == 0} > 1


(1...v).each do |u|
  p = parent[u]
  # parent 0 は検査しない
  res[p] = true if p != 0 and prenum[p] <= lowest[u]
end

res = res.each.with_index.select{|i, idx| i }.map{|i| i[1]}
puts res.join("\n") unless res.empty?
