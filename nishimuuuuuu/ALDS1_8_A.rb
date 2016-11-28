num = gets.chomp.to_i

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

tree= []

def root(tree)

end


def insert(tree, z)
  y = nil
  x = root(tree)
  until x.nil?
    y = x
    if z.key < x.key
      x = x.left
    else
      x = x.right
    end
  end
  z.p = y
  
  if y.nil?
    rootid = z
  elsif z.key < y.key
    y.left = z
  else
    y.right = z
  end
  tree
end

num.times do |i|
  tree[i] = Node.new(-1,-1,-1) 
end

num.times do |i|
  i = gets.chomp.split.map(&:to_i)
  cmd = i[0]
  if cmd == 'insert'
    v = i[1]
  end

  if cmd == 'print'
    puts inorder(u, tree, []).join(' ')
    puts preorder(u, tree, []).join(' ')
  end
end

