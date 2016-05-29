hash = {}
n = gets.to_i

n.times do
  command, key = gets.chomp.split(' ').map(&:to_s)
  if command == 'insert'
    hash[key] = true
  else
    puts hash[key] ? 'yes' : 'no'
  end
end
