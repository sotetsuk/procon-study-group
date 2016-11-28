n = gets.to_i
dic = {}
(0..n-1).each do |i|
  order, word = gets.chomp.split(" ")
  if(order=="insert") then
    dic[word] = true
  end
  if(order=="find")
    if (dic[word] == true) then
      puts "yes"
    else
      puts "no"
    end
  end
end

def h1(key)
  return key % M
end

def h2(key)
  return (1 + (key % (M-1)))
end
