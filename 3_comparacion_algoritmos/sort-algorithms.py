import sys
import os
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt

with open("insertionSort_cpp_time.txt") as r:
    content = r.readlines()

content = [x.strip() for x in content]
mat = []
for line in content:
    s = line.split(' ')
    sad = [ int(s[0]), float(s[1])]
    mat.append(sad)

with open("selectionSort_cpp_time.txt") as r1:
    content2 = r1.readlines()

content2 = [x2.strip() for x2 in content2]
mat2 = []
for line2 in content2:
    s = line2.split(' ')
    sad2 = [ int(s[0]), float(s[1])]
    mat2.append(sad2)

with open("insertionSort_java_time.txt") as r2:
    content3 = r2.readlines()

content3 = [x.strip() for x in content3]
mat3 = []
for line in content3:
    s = line.split(' ')
    if s[0].isdigit():
        mat3.append(s)

selt = np.array(mat)
selection = selt.astype(np.float64)
inst = np.array(mat2)
insertion = inst.astype(np.float64)
jav = np.array(mat3)
java = jav.astype(np.float64)

#print(content)
#print(mat)

x, y = selt.T
r, s = inst.T
#k, m = jav.T


plt.plot(x, y, label='insertion')
plt.plot(x, s, label='selection')
#plt.plot(k, m, label='java')
#plt.scatter(x,y)
#plt.scatter(r,s)

plt.xlabel('x label')
plt.ylabel('y label')
plt.title("Sort Algorithms")
plt.legend()

plt.savefig('selection_insertion.png')
#print(selection)
#print(data.shape)