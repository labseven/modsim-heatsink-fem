# Imports the output into python and then visualize it

# tempraturesTimeArray holds [iteration#][0: time, 1+:z level][y level]

import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import matplotlib.animation as animation


zLevelResolution = 1
yLevelToGraph = 10
plotNumberToGraph = -1

# Import the array
with open("./graphsAndShit/outputPythonMedium.csv","r") as fileIn:
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
		print("Time: ", time);

		tempraturesList = [];
		for z in range(xyzSize[2]):
			for y in range(xyzSize[1]):
				currLine = fileIn.readline();
				if (z%zLevelResolution == 0):
					if(y == yLevelToGraph):
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

for z in range(0,xyzSize[2],zLevelResolution):
		for x in range(xyzSize[0]):
			xList = xList + [x];
			zList = zList + [z];


# print("xList: ", xList);
# print("yList: ", yList);
# print("zList: ", zList);




# Plot it
fig = plt.figure()
ax = fig.add_subplot(111)

print("Number of simulations: ", len(tempraturesTimeArray))
print("Time of simulation: ", tempraturesTimeArray[plotNumberToGraph][0])
print("Tempratures: ", tempraturesTimeArray[plotNumberToGraph][1])

colormap = cm.get_cmap("plasma");

cax = ax.scatter(xList,zList, cmap=colormap, c=tempraturesTimeArray[plotNumberToGraph][1], s=150, alpha=.8);

ax.set_xlabel('X')
ax.set_ylabel('Y')


plt.colorbar(cax);

plt.show()



print("Done!");