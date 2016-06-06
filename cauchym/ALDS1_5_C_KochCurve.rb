include Math


n = gets.to_i

Point = Struct.new("Point", :x, :y)
s, t, u, a, b = Point.new(0.0, 0.0)
a = Point.new(0.0, 0.0)
b = Point.new(100.0, 0.0)



def koch(d, a, b)
  return if d==0

  th = PI * 60.0 /180.0
  s = Point.new(0.0, 0.0)
  t = Point.new(0.0, 0.0)
  u = Point.new(0.0, 0.0)

  s.x =  (2.0 * a.x + 1.0 * b.x) / 3.0
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) +  s.x
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) +  s.y

  koch(d-1, a, s)
  puts ("#{s.x} #{s.y}")
  koch(d-1, s, u)
  puts "#{u.x} #{u.y}"
  koch(d-1, u, t)
  puts "#{t.x} #{t.y}"
  koch(d-1, t, b)
end

puts "#{a.x} #{a.y}"
koch(n, a, b)
puts "#{b.x} #{b.y}"
