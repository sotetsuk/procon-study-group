deg, dis = gets.chomp.split.map(&:to_i)

deg = deg / 10.0
dis = dis / 60.0
dis = dis.round(1)
huko = ''
case deg
when 11.25...33.75
  huko = 'NNE'
when 33.75...56.25
  huko = 'NE'
when 56.25...78.75
  huko = 'ENE'
when 78.75...101.25
  huko = 'E'
when 101.25...123.75
  huko = 'ESE'
when 123.75...146.25
  huko = 'SE'
when 146.25...168.75
  huko = 'SSE'
when 168.75...191.25
  huko = 'S' 
when 191.25...213.75
  huko = 'SSW'
when 213.75...236.25
  huko = 'SW'
when 236.25...258.75
  huko = 'WSW'
when 258.75...281.25
  huko = 'W'
when 281.25...303.75
  huko = 'WNW'
when 303.75...326.25
  huko = 'NW'
when 326.25...348.75
  huko = 'NNW'
else 
  huko = 'N'
end


huryoku = 0
case dis
when 0.0..0.2
  huryoku = 0
when 0.3..1.5
  huryoku = 1
when 1.6..3.3
  huryoku = 2
when 3.4..5.4
  huryoku = 3
when 5.5..7.9
  huryoku = 4
when 8.0..10.7
  huryoku = 5
when 10.8..13.8
  huryoku = 6
when 13.9..17.1
  huryoku = 7
when 17.2..20.7
  huryoku = 8
when 20.8..24.4
  huryoku = 9
when 24.5..28.4
  huryoku = 10
when 28.5..32.6
  huryoku = 11
else
  huryoku = 12
end

huko = 'C' if huryoku == 0

puts "#{huko } #{huryoku}"
