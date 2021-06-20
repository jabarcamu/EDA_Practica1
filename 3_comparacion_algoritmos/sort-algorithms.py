import sys
import os
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt

with open("../2_implementacion_algoritmos/cpp/insertionSort_cpp_time.txt") as r:
    content = r.readlines()

content = [x.strip() for x in content]
mat = []
for line in content:
    s = line.split(' ')
    sad = [ int(s[0]), float(s[1])]
    mat.append(sad)

with open("../2_implementacion_algoritmos/cpp/selectionSort_cpp_time.txt") as r1:
    content2 = r1.readlines()

content2 = [x2.strip() for x2 in content2]
mat2 = []
for line2 in content2:
    s = line2.split(' ')
    sad2 = [ int(s[0]), float(s[1])]
    mat2.append(sad2)

selt = np.array(mat)
selection = selt.astype(np.float64)
inst = np.array(mat2)
insertion = inst.astype(np.float64)

x, y = selt.T
r, s = inst.T

plt.plot(x, y, label='insertion')
plt.plot(x, s, label='selection')

plt.xlabel('x label')
plt.ylabel('y label')
plt.title("Sort Algorithms in C++")
plt.legend()

plt.savefig('selection_insertion.png')