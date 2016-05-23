array = STDIN.gets.split(" ")
stack = []

(0..(array.length-1)).each{ |i|
  if  array[i] == "+"
    tmp = stack[-2] + stack[-1]
    stack.delete_at(-1)
    stack.delete_at(-2)
    stack.push(tmp)
  elsif array[i] == "-"
    tmp = stack[-2] - stack[-1]
    stack.delete_at(-1)
    stack.delete_at(-2)
    stack.push(tmp)
  elsif array[i] == "*"
    tmp = stack[-2] * stack[-1]
    stack.delete_at(-1)
    stack.delete_at(-2)
    stack.push(tmp)
  else
    stack.push(array[i].to_i)
  end
}

puts stack
