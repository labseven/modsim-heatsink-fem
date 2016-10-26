# Imports the output into python and then visualize it

# tempraturesTimeArray holds [iteration#][0: time, 1+:z level][y level]

import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.cm as cm



# Import the array
with open("outputPython1.csv","r") as fileIn:
	currLine = fileIn.readline();

	xyzSize = [int(n) for n in currLine.rstrip('\n').split(",")];

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
		tempraturesTimeArray.append(time + [tempraturesArray]);

print;
print("Time and temp: ", tempraturesTimeArray);

print("Time of first thing: ", tempraturesTimeArray[0][0]);
print("Tempratures of first thing: ", tempraturesTimeArray[0][1]);







# Plot it
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')



c = .83;
colormap = cm.get_cmap("hot");


ax.scatter(range(4),range(4),range(4), c='r', cmap=colormap);

# for z in range(xyzSize[2]):
# 	for y in range(xyzSize[1]):
# 		for x in range(xyzSize[0]):
# 			print(x, " ", y, " ", z);
# 			ax.scatter(x,y,z, c=c, cmap=colormap);
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