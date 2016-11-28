Node = Struct.new(:p, :l, :r)
@tree = []
# @tree = Array.new(25, Node.new(-1, -1, -1))だと初期化にNodeが同じアドレスを指してしまう
# いい方法がないか

def preParse(u)
  return if u == -1
  print " " + u.to_s
  preParse(@tree[u].l)
  preParse(@tree[u].r)
end

def inParse(u)
  return if u == -1
  inParse(@tree[u].l)
  print " " + u.to_s
  inParse(@tree[u].r)
end

def postParse(u)
  return if u == -1
  postParse(@tree[u].l)
  postParse(@tree[u].r)
  print " " + u.to_s
end

n = gets.to_i

n.times do |i|
  @tree[i] = Node.new(-1, -1, -1)
end

n.times do
  v, l, r = gets.chomp.split(' ').map(&:to_i)
  @tree[v].l = l
  @tree[v].r = r
  @tree[l].p = v if l != -1
  @tree[r].p = v if r != -1
end

root = 0
n.times do |i|
  root = i if @tree[i].p == -1
end

puts 'Preorder'
preParse(root)
puts
puts 'Inorder'
inParse(root)
puts
puts 'Postorder'
postParse(root)
puts
