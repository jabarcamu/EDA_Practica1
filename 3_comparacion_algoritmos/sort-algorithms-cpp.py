import sys
import os
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt

#lectura de tiempos del Insertion  Sort
with open("../2_implementacion_algoritmos/cpp/insertionSort_cpp_time.txt") as r:
    content = r.readlines()

content = [x.strip() for x in content]
mat = []
for line in content:
    s = line.split(' ')
    sad = [ int(s[0]), float(s[1])]
    mat.append(sad)

#Lectura de tiempos del Selection Sort
with open("../2_implementacion_algoritmos/cpp/selectionSort_cpp_time.txt") as r1:
    content2 = r1.readlines()

content2 = [x2.strip() for x2 in content2]
mat2 = []
for line2 in content2:
    s = line2.split(' ')
    sad2 = [ int(s[0]), float(s[1])]
    mat2.append(sad2)

#Lectura de tiempo del HeapSort
with open("../2_implementacion_algoritmos/cpp/heapsort_cpp_time.txt") as r1:
    content3 = r1.readlines()

content3 = [x3.strip() for x3 in content3]
mat3 = []
for line3 in content3:
    s = line3.split(' ')
    sad3 = [ int(s[0]), float(s[1])]
    mat3.append(sad3)

#Lectura de tiempos del QuickSort
with open("../2_implementacion_algoritmos/cpp/quicksort_cpp_time.txt") as r1:
    content4 = r1.readlines()

content2 = [x4.strip() for x4 in content4]
mat4 = []
for line2 in content4:
    s = line2.split(' ')
    sad4 = [ int(s[0]), float(s[1])]
    mat4.append(sad4)

#Lectura de tiempos del Counting Sort
with open("../2_implementacion_algoritmos/cpp/countingSort_cpp_time.txt") as r1:
    content5 = r1.readlines()

content2 = [x5.strip() for x5 in content5]
mat5= []
for line2 in content5:
    s = line2.split(' ')
    sad5 = [ int(s[0]), float(s[1])]
    mat5.append(sad5)

#Lectura de tiempos del Merge Sort
with open("../2_implementacion_algoritmos/cpp/mergeSort_cpp_time.txt") as r1:
    content6 = r1.readlines()

content2 = [x6.strip() for x6 in content6]
mat6= []
for line2 in content6:
    s = line2.split(' ')
    sad6 = [ int(s[0]), float(s[1])]
    mat6.append(sad6)

#Lectura de tiempos del Bubble Sort
with open("../2_implementacion_algoritmos/cpp/tiempo_bubble_sort_cpp.txt") as r1:
    content7 = r1.readlines()

content2 = [x7.strip() for x7 in content7]
mat7= []
for line2 in content7:
    s = line2.split(' ')
    sad7 = [ int(s[0]), float(s[1])]
    mat7.append(sad7)




#conviertiendo lista en numpy array
selt = np.array(mat)
selection = selt.astype(np.float64)

inst = np.array(mat2)
insertion = inst.astype(np.float64)

heap_t = np.array(mat3)
heapsort_time = heap_t.astype(np.float64)

quick_t = np.array(mat4)
quicksort_time = quick_t.astype(np.float64)

count_t = np.array(mat5)
counting_time = count_t.astype(np.float64)

mer_t = np.array(mat6)
merge_time = mer_t.astype(np.float64)

bub_t = np.array(mat7)
bubble_time = bub_t.astype(np.float64)

a1, a2 = selt.T
b1, b2 = inst.T
c1, c2 = heapsort_time.T
d1, d2 = quicksort_time.T
e1, e2 = counting_time.T
f1, f2 = merge_time.T
g1, g2 = bubble_time.T

#Grafica de las funciones de ordenamiento

plt.plot(a1, a2, label='insertion')
plt.plot(b1, b2, label='selection')
plt.plot(c1, c2, label='heapsort')
plt.plot(d1, d2, label='quicksort')
plt.plot(e1, e2, label='counting')
plt.plot(f1, f2, label='mergesort')
plt.plot(g1, g2, label='bubble')


plt.xlabel('Data Procesada')
plt.ylabel('Tiempo(Segundos)')
plt.title("Sort Algorithms in C++")
plt.legend()

plt.savefig('sort-algorithms-cpp.png')
