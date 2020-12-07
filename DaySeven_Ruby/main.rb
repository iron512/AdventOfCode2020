#!/usr/bin/env ruby
filename =ARGV[0]

file = File.open(filename)
map = Hash.new

for line in file 
	if not line.match(/no other/)
		line = line.gsub("bags contain ", "").gsub(",","").gsub(".","").gsub("bags","").gsub("bag","").gsub("  "," ")
		line = line.split(" ")

		key = line[0]+line[1]
		tot = Array.new

		(2..(line.length()+1)/3).each do |x|
			qt = line[x]
			color = line[x+1]+line[x+2]
			tot.push color
		end

		map[key] = tot
	end
end

poss = Array.new
poss.push 'shinygold'

#filled
changed = true

while changed do
	changed = false
		
	map.each do |item, arr|

  		poss.each do |elem|
  			if arr.include? elem then
  				changed = true
  				poss.push item
  				arr.clear
  			end
  		end
	end

end

puts poss.length() -1
