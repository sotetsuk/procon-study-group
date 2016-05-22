def sortByBubble(a, n)
  n.times do |i|
    (n-1).downto(i+1) do |j|
      a[j], a[j-1] = a[j-1], a[j] if a[j][1] < a[j-1][1]
    end
  end
  puts a.join(' ')
end

def sortBySelection(a, n)
  n.times do |i|
    minj = i
    i.upto(n-1) do |j|
      minj = j if a[j][1] < a[minj][1]
    end
    a[i], a[minj] = a[minj], a[i]
  end
  puts a.join(' ')
end

def checkStable(n, origin, sorted)
  originOrder = {1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => ''}
  sortedOrder = {1 => '', 2 => '', 3 => '', 4 => '', 5 => '', 6 => '', 7 => '', 8 => '', 9 => ''}
  n.times do |i|
    originOrder[origin[i][1].to_i] << origin[i][0]
    sortedOrder[sorted[i][1].to_i] << sorted[i][0]
  end
  puts originOrder == sortedOrder ? 'Stable' : 'Not stable'
end

n = gets.to_i
origin = gets.chomp.split(' ').map(&:to_s)
bubble = Marshal.load(Marshal.dump(origin))
selection = Marshal.load(Marshal.dump(origin))
sortByBubble(bubble, n)
checkStable(n, origin, bubble)
sortBySelection(selection, n)
checkStable(n, origin, selection)
