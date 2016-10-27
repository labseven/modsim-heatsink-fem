import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
x, y, z, v = (np.random.random((4,100))-0.5)*15
print(v);
c = np.abs(v) + 10
print(c);

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
cmhot = plt.get_cmap("hot")
print(cmhot);
cax = ax.scatter(x, y, z, v, s=50, c=c, cmap=cmhot)

plt.show()