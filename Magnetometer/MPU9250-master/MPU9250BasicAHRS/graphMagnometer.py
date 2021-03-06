from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
x,y,z = [], [],[]
with open('xyzData.txt') as f:
    for l in f:
        row = l.split()
        x.append(int(float(row[0])))
        y.append(int(float(row[1])))
        z.append(int(float(row[2])))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d' )

ax.scatter(x, y, z, c='r', marker='o')

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
#plt.scatter(x, y, z)
plt.show()