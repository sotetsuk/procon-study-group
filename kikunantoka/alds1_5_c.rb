
def koch(n, a, b)
  return true if n == 0
  th = Math::PI * 60.0 / 180.0
  s = {
    x: (2.0 * a[:x].to_f + 1.0 * b[:x].to_f) / 3.0,
    y: (2.0 * a[:y].to_f + 1.0 * b[:y].to_f) / 3.0
  }
  t = {
    x: (1.0 * a[:x].to_f + 2.0 * b[:x].to_f) / 3.0,
    y: (1.0 * a[:y].to_f + 2.0 * b[:y].to_f) / 3.0
  }
  u = {
    x: (t[:x] - s[:x]) * Math::cos(th) - (t[:y] - s[:y]) * Math::sin(th) + s[:x],
    y: (t[:x] - s[:x]) * Math::sin(th) + (t[:y] - s[:y]) * Math::cos(th) + s[:y]
  }

  koch(n-1, a, s)
  puts format('%.8f %.8f', s[:x].to_f, s[:y].to_f)
  koch(n-1, s, u)
  puts format('%.8f %.8f', u[:x].to_f, u[:y].to_f)
  koch(n-1, u, t)
  puts format('%.8f %.8f', t[:x].to_f, t[:y].to_f)
  koch(n-1, t, b)
end

n = gets.to_i
a = {x: 0.0, y: 0.0}
b = {x: 100.0, y: 0.0}
puts format('%.8f %.8f', a[:x].to_f, a[:y].to_f)
koch(n, a, b)
puts format('%.8f %.8f', b[:x].to_f, b[:y].to_f)
