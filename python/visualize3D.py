# Imports the output into python and then visualize it

# tempraturesTimeArray holds [iteration#][0: time, 1+:z level][y level]

import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt


with open("outputPython1.csv","r") as fileIn:
	currLine = fileIn.readline();

	xyzSize = [int(n) for n in currLine.rstrip('\n').split(",")];

	fig = plt.figure()
	ax = fig.add_subplot(111, projection='3d')

	for z in range(xyzSize[2]):
		for y in range(xyzSize[1]):
			for x in range(xyzSize[0]):
				ax.scatter(x,y,z, c='b',marker='^');
			
	print (xyzSize);
	#print(xyzSize[1]);
	tempraturesArray = [[[] for i in range(xyzSize[1])] for i in range(xyzSize[2])];
	tempraturesTimeArray = [];
	# print (tempraturesArray);

	while(1):
		currLine = fileIn.readline();
		if(not currLine): break;
		time = [int(currLine.rstrip('\n'))];
		print("Time: ", time);

		for z in range(xyzSize[2]):
			for y in range(xyzSize[1]):
				currLine = fileIn.readline();
				bigAssList = currLine.split(",");
				bigAssList.pop(); # removes the last element, which is \n or empty
				bigAssList = [float(n) for n in bigAssList];
				#print("Line",z, y,":", bigAssList);
				tempraturesArray[z][y] = bigAssList;
		print("Tempratures: ",tempraturesArray);
		tempraturesTimeArray.append(time + tempraturesArray);

print;
print("Time and temp: ", tempraturesTimeArray);

print("Time of first thing: ", tempraturesTimeArray[0][0]);
print("Tempratures of 2nd z level, 2nd row of first thing: ", tempraturesTimeArray[0][2][1]);

def randrange(n, vmin, vmax):
    return (vmax - vmin)*np.random.rand(n) + vmin


# n = 100
# for c, m, zl, zh in [('b', '^', -30, -5),('r', '^', -30, -5)]:
#     xs = randrange(n, 23, 32)
#     ys = randrange(n, 0, 100)
#     zs = randrange(n, zl, zh)
#     ax.scatter(xs, ys, zs, c=c, marker=m)

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()


print("Done!");