#MERGE SORT diagram
import sys
import os
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt


#Lectura de tiempos de cada tipo de implementacion
with open("../2_implementacion_algoritmos/python/mergeSort_python_time.txt") as r:
    content = r.readlines()

content = [x.strip() for x in content]
mat = []
for line in content:
    s = line.split(' ')
    sad = [ int(s[0]), float(s[1])]
    mat.append(sad)


with open("../2_implementacion_algoritmos/cpp/mergeSort_cpp_time.txt") as r1:
    content2 = r1.readlines()

content2 = [x2.strip() for x2 in content2]
mat2 = []
for line2 in content2:
    s = line2.split(' ')
    sad2 = [ int(s[0]), float(s[1])]
    mat2.append(sad2)


pyt = np.array(mat)
python = pyt.astype(np.float64)

cpp = np.array(mat2)
cplusplus = cpp.astype(np.float64)


x, y = pyt.T
r, s = cpp.T


plt.plot(x, y, label='python')
plt.plot(x, s, label='c++')

plt.xlabel('x label')
plt.ylabel('y label')
plt.title("merge sort")
plt.legend()

plt.savefig('merge_diagram.png')


