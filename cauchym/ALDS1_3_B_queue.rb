n, quantum = gets.chomp.split.map(&:to_i)
queue = []
n.times{
    name, sec = gets.chomp.split
    queue.push [name, sec.to_i]
}

time = 0
until queue.empty?
    process = queue.shift
    # p process
    if process[1] <= quantum
        # p "足りた"
        time += process[1]
        puts "#{process[0]} #{time}"
    else
        # p "足りない"
        time += quantum
        queue.push [process[0], process[1] - quantum]
        # p "あと#{process[1] - quantum}"
    end
end
