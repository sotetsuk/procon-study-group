n = gets.chomp.to_i
hsh = {}
class Node
  attr_reader :id
  attr_accessor :children,:parent, :depth, :type
  def initialize(id)
    @id = id
    @parent = -1
    @depth = 0
    @type = nil
    @children = []
  end

  def leaf?
    @children.empty?
  end
end

def identify(node, depth, node_list)
  node.depth = depth
  if node.parent == -1
    node.type = 'root'
  elsif node.leaf?
      node.type = 'leaf'
  else
    node.type = 'internal node'
  end
  node.children.each do |i|
    identify(node_list[i], depth + 1, node_list)
  end
end

n.times do |index|
  hsh[index] = Node.new(index)
end
 
n.times do
  arr = gets.chomp.split.map(&:to_i)
  id = arr.shift
  num = arr.shift
  hsh[id].children = arr if num > 0
  arr.each do |item|
    hsh[item].parent = id
  end
end

root = hsh.select{|key, val| val.parent == -1}
identify(root.values[0], 0, hsh)
 
hsh.each do |key, node|
  puts "node #{node.id}: parent = #{node.parent}, depth = #{node.depth}, #{node.type}, #{node.children}"
end
