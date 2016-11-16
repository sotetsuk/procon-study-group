
def preorder(u, tree, res)
  return if u == -1
  res << u 
  preorder(tree[u].left, tree, res)
  preorder(tree[u].right, tree, res)
  res
end
 
def inorder(u, tree, res)
  return if u == -1
  inorder(tree[u].left, tree, res)
  res << u
  inorder(tree[u].right, tree, res)
  res
end
 
def postorder(u, tree, res)
  return if u == -1
  postorder(tree[u].left, tree, res)
  postorder(tree[u].right, tree, res)
  res << u
  res
end
 
class Node
  attr_accessor :left, :right, :parent
  def initialize(parent, left, right)
    @parent = parent
    @left = left
    @right = right
  end
end

n = gets.chomp.to_i
 
tree = []
n.times do |i|
  tree[i] = Node.new(-1, -1, -1)
end


 

n.times do
  id, l, r = gets.chomp.split(' ').map(&:to_i)
  tree[id].left = l
  tree[id].right = r
  tree[l].parent = id if l != -1
  tree[r].parent = id if r != -1
end
 
root = tree.index{|i| i.parent == -1}

puts 'Preorder'
puts " #{preorder(root, tree, []).join(' ')}"
puts 'Inorder'
puts " #{inorder(root, tree, []).join(' ')}"
puts 'Postorder'
puts " #{postorder(root, tree, []).join(' ')}"
