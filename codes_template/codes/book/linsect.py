#Code by GVV Sharma
#July 25, 2024
#released under GNU GPL
#Line intersection


import sys                                          #for path to external scripts
sys.path.insert(0, '/sdcard/github/matgeo/codes/CoordGeo')        #path to my scripts
import numpy as np
import mpmath as mp
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen


#if using termux
import subprocess
import shlex
#end if


#Given Points
#A = np.array(([3, 2])).reshape(-1,1) 
#Line parameters
n1 = np.array(([1, 0])).reshape(-1,1) 
c1 = 5/22
n2 = np.array(([1, -7])).reshape(-1,1) 
c2 = -5 
n3 = np.array(([3, 1])).reshape(-1,1) 
c3 =  0

k1 = -1
k2 = 1
#Generating Lines
x_A = line_norm(n1,c1,k1,k2)
k1 = -0.5
k2 = 0.5
x_C = line_norm(n3,c3,k1,k2)
k1 = 0.001
k2 = -1
x_B = line_norm(n2,c2,k1,k2)

A = line_isect(n2,c2,n3,c3)
print(A, 5/22*np.array(([-1, 3])).reshape(-1,1) )

#Plotting all lines
plt.plot(x_A[0,:],x_A[1,:],label='$(1 \quad 0)\mathbf{x}=\\frac{5}{22}$')
plt.plot(x_B[0,:],x_B[1,:],label='$(1 \quad -7)\mathbf{x}=-5$')
plt.plot(x_C[0,:],x_C[1,:],label='$(3 \quad 1)\mathbf{x}=0$')

colors = np.arange(1,2)
#Labeling the coordinates
tri_coords = np.block([A])
plt.scatter(tri_coords[0,:], tri_coords[1,:], c=colors)
vert_labels = ['A']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
    #plt.annotate(f'{txt}\n({tri_coords[0,i]:.2f}, {tri_coords[1,i]:.2f})',
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(-10,5), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

# use set_position
ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')
'''
ax.spines['left'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['bottom'].set_visible(False)
plt.xlabel('$x$')
plt.ylabel('$y$')
'''
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
plt.savefig('chapters/11/10/4/6/figs/fig.pdf')
subprocess.run(shlex.split("termux-open chapters/11/10/4/6/figs/fig.pdf"))
#else
#plt.show()
