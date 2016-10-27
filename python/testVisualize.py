import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import matplotlib.cm as cm

x = list(range(10));
y = list(range(10));
z = list(range(10));

t = [5]*5 + [10]*5;


print (x, y, z, t);
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')




colormap = cm.get_cmap("spring");

ax.scatter(x,y,z, cmap=colormap, c=t);


ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()



print("Done!");