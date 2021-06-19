#insertion sort diagram
import sys
import os
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt

with open("insertionSort_python_time.txt") as r:
    content = r.readlines()

content = [x.strip() for x in content]
mat = []
for line in content:
    s = line.split(' ')
    sad = [ int(s[0]), float(s[1])]
    mat.append(sad)

with open("insertionSort_cpp_time.txt") as r1:
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
    sad3 = [ int(s[0]), float(s[1])]
    mat3.append(sad3)

pyt = np.array(mat)
python = pyt.astype(np.float64)
cpp = np.array(mat2)
cplusplus = cpp.astype(np.float64)
jav = np.array(mat3)
java = jav.astype(np.float64)

x, y = pyt.T
r, s = cpp.T
k, m = jav.T


plt.plot(x, y, label='python')
plt.plot(x, s, label='c++')
plt.plot(x, m, label='java')


plt.xlabel('x label')
plt.ylabel('y label')
plt.title("insertion sort")
plt.legend()

plt.savefig('insertion_diagram.png')

#print(selection)
#print(data.shape)