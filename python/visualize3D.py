# Imports the output into python and then visualize it

with open("outputPython1.csv","r") as fileIn:
	currLine = fileIn.readline();

	xyzSize = [int(n) for n in currLine.rstrip('\n').split(",")];

	print (xyzSize);

	for z in range(xyzSize[2]):
		for y in range(xyzSize[1]):
			for x in range(xyzSize[0]):
				print("Line",x,":", fileIn.readline());