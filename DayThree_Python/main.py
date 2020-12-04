import sys

if len(sys.argv) != 2:
	print("Wrong parameters passed. Please run using again using the correct syntax:\n\npython3 main.py <input_file_name>")

f = open(sys.argv[1],"r").readlines()

diplacements = [(1,1), (3,1), (5,1), (7,1), (1,2)]

rightDisplacement = 0
downDisplacement = 0

originalTrees = 0
finalproduct = 1

for pair in diplacements:
	(rightDisplacement,downDisplacement) = pair

	meters = 0
	trees = 0

	for x in range(downDisplacement, len(f), downDisplacement):
		meters += rightDisplacement
		x = f[x].replace("\n","")

		if (list(x)[meters%len(x)] == '#'):
			trees +=1

	finalproduct *= trees

	#print(trees)

	if pair == (3,1):
		print("During our trip with the toboggan (3,1), we met " +  str(trees) + " trees.")

print("During our trips with all toboggans, we would have met a product of " +  str(finalproduct) + " trees.")

