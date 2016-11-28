class Node
  attr_accessor :id, :parent, :left, :right
 
  def initialize(id, parent = nil, left = nil, right = nil)
    @id = id
    @parent = parent
    @left = left
    @right = right
  end
end
 
class BinaryTree
  attr_accessor :nodes
 
  def initialize(data)
    @nodes = data.each_with_object({}) do |(k, v), hash|
      hash[k] = Node.new(k, v['parent'], v['left'], v['right'])
    end
  end
 
  def depth(id)
    node = @nodes[id]
    unless node.parent.nil?
      return depth(node.parent) + 1
    else
      return 0
    end
  end
 
  def root?(id)
    node = @nodes[id]
    node.parent.nil?
  end
 
  def leaf?(id)
    children(id).empty?
  end
 
  def sibling(id)
    parent = @nodes[id].parent
    unless parent.nil?
      s = children(parent).reject { |i| id == i }
      return s.any? ? s.shift : -1
    end
    -1
  end
 
  def degree(id)
    children(id).length
  end
 
  def height(id)
    c = children(id)
    unless c.empty?
      heights = []
      c.each do |child|
        heights << height(child) + 1
      end
      return heights.max
    else
      return 0
    end
  end
 
  private
  def children(id)
    node = @nodes[id]
    [node.left, node.right].reject { |i| i == -1 }
  end
end
 
data = {}
parent = {}
 
n = gets.chop.to_i
 
n.times do
  id, left, right = gets.chop.split.map(&:to_i)
  data[id] = { :left => left, :right => right }
  parent[left] = parent[right] = id
end
 
data.each do |key, value|
  value[:parent] = parent[key]
end
 
data = Hash[data.sort]
 
t = BinaryTree.new(data)
 
t.nodes.each do |id, node|
  out = []
  out << "node #{id}: parent = " + (!node.parent.nil? ? node.parent : -1).to_s
  out << "sibling = " + t.sibling(id).to_s
  out << "degree = " + t.degree(id).to_s
  out << "depth = " + t.depth(id).to_s
  out << "height = " + t.height(id).to_s
  out << (t.root?(id) ? "root" : t.leaf?(id) ? "leaf" : "internal node").to_s
  puts out.join(', ')
end
