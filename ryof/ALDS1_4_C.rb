#! /usr/bin/env ruby
$m = 1046527
n = STDIN.gets.chomp.to_i
$t = []
class String
	def key
		sum, p = 0, 1
		self.each_char do |ch|
			num = nil
			case ch
			when 'A'
				num = 1
			when 'C'
				num = 2
			when 'G'
				num = 3
			when 'T'
				num = 4
			end
			sum += p * num
			p *= 5
		end
		sum
	end
end
def calc_hash data, i
	((data.key % $m) + i * (1 + (data.key % ($m - 1)))) % $m
end
def insert data
	i = 0
	hash = nil
	while i < $m
		hash = calc_hash(data, i)
		if $t[hash] == data
			return
		elsif $t[hash] == nil
			$t[hash] = data
			return
		end
		i += 1
	end
	raise 'omg'
end
def search data
	i = 0
	while i < $m
		hash = calc_hash(data, i)
		if $t[hash] == data
			return true
		elsif $t[hash] == nil
			return false
		else
			i += 1
		end
	end
	return false
end
output = []
n.times do
	commandline = STDIN.gets.chomp.split(' ')
	command = commandline[0]
	arg = commandline[1]
	case command
	when 'insert'
		insert arg
	when 'find'
		output << (search(arg) ? 'yes' : 'no')
	end
end
output.each { |o| STDOUT.puts o }
