import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np

x1,y1,x2, y2,x3,y3,x4,y4 = np.genfromtxt('example.csv', delimiter=',', unpack=True)
fig, ax = plt.subplots()
x = [x1,x2,x3,x4]
y = [y1,y2,y3,y4]

colours = ['red','black','green','orange']
labels = ['sun','earth','riza','citi']
ax.set_xlim(-400, 800)
ax.set_ylim(-800, 400)
ax.legend(labels)

def update(i =int):
    for j in range(4):
        ax.plot(x[j][:i],y[j][:i],color= colours[j])
        
        
animator = FuncAnimation(fig, update, interval = 100)

ax.set_title('Orbit')
#ax.legend()
plt.show()