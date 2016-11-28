gets.chomp
preorderd = gets.chomp.split.map(&:to_i)
inorderd  = gets.chomp.split.map(&:to_i)



def make_tree(inorderd, preorderd)
  return [] if inorderd.nil? or inorderd.empty? 
  return [] if preorderd.nil? or preorderd.empty? 

  focus = preorderd.shift
  split = inorderd.index(focus)

  l = inorderd.shift(split)
  inorderd.shift

  [make_tree(l, preorderd), make_tree(inorderd, preorderd)].flatten << focus
end

puts make_tree(inorderd, preorderd).join(' ')


