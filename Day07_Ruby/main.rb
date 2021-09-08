#!/usr/bin/env ruby
require 'ostruct'

filename =ARGV[0]

file = File.open(filename)
map = Hash.new 

for line in file 
	if not line.match(/no other/)
		line = line.gsub("bags contain ", "").gsub(",","").gsub(".","").gsub("bags","").gsub("bag","").gsub("  "," ")
		puts line
		line = line.split(" ")

		key = line[0]+line[1]
		tot = Array.new

		(0..((line.length()-2)/3)-1).each do |x|
			qt = line[x*3+2]
			color = line[x*3+3]+line[x*3+4]
			
			el = OpenStruct.new
			el.head = qt.to_i
			el.tail = color

			tot.push el
		end
		map[key] = tot
		puts tot
	end
end

poss = Array.new
shiny = OpenStruct.new
shiny.head = 1
shiny.tail = "shinygold"
poss.push shiny

#filled
changed = true
i = 0

fintot = 0

while changed or i < 600 do
	i = i + 1
	changed = false
	
	poss.each do |elem|
		if map.key?(elem.tail) then
			changed = true
			i = 0
			map[elem.tail].each do |item|
				newstr = OpenStruct.new
				newstr.head = item.head*elem.head
				newstr.tail = item.tail
				poss.push newstr	
				puts "inseting #{item.head*elem.head} #{item.tail} as it comes from #{elem}"
			end

			fintot = fintot+elem.head
			poss.delete elem
			puts poss
		end
	end
end

poss.each do |elem|
	fintot = fintot+elem.head
end

puts fintot
