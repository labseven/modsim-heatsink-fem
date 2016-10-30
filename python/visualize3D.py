# Imports the output into python and then visualize it

# tempraturesTimeArray holds [iteration#][0: time, 1+:z level][y level]

import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.cm as cm



# Import the array
with open("outputPython.csv","r") as fileIn:
	currLine = fileIn.readline();

	xyzSize = [int(n) for n in currLine.rstrip('\n').split(",")];

	print (xyzSize);
	#print(xyzSize[1]);
	tempraturesList = [];
	tempraturesTimeArray = [];
	xList = [];
	yList = [];
	zList = [];
	# print (tempraturesArray);

	while(1):
		currLine = fileIn.readline();
		if(not currLine): break;
		time = [float(currLine.rstrip('\n'))];
		# print("Time: ", time);

		tempraturesList = [];
		for z in range(xyzSize[2]):
			for y in range(xyzSize[1]):
				currLine = fileIn.readline();
				bigAssList = currLine.split(",");
				bigAssList.pop(); # removes the last element, which is \n or empty
				bigAssList = [float(n) for n in bigAssList];
				tempraturesList = tempraturesList + bigAssList;
		# print("Tempratures: ",tempraturesList);
		# print();
		tempraturesTimeArray.append(time + [tempraturesList]);

# print;
# print("Time and temp: ", tempraturesTimeArray);

# print("Time of first thing: ", tempraturesTimeArray[0][0]);
# print("Tempratures of first thing: ", tempraturesTimeArray[0][1]);

for z in range(xyzSize[2]):
	for y in range(xyzSize[1]):
		for x in range(xyzSize[0]):
			xList = xList + [x];
			yList = yList + [y];
			zList = zList + [z];


# print("xList: ", xList);
# print("yList: ", yList);
# print("zList: ", zList);




# Plot it
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')




colormap = cm.get_cmap("plasma");

ax.scatter(xList,yList,zList, cmap=colormap, c=tempraturesTimeArray[0][1], s=70, alpha=.6);


ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()



print("Done!");