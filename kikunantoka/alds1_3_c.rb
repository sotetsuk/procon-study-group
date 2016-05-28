def doCommand(command, key, list)
  command == 'insert' ? list.unshift(key) :
    command == 'delete' ? list.index(key) && list.delete_at(list.index(key)) :
    command == 'deleteFirst' ? list.shift : list.pop
end

n = gets.to_i
list = []
n.times do
  command, key = gets.chomp.split(' ').map(&:to_s)
  doCommand(command, key, list)
end

puts list.join(' ')
