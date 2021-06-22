
# Fuente : https://www.geeksforgeeks.org/merge-sort/
import numpy as np
import sys
import time
import os
from tqdm import tqdm



# Python program for implementation of MergeSort
def mergeSort(arr):
	if len(arr) > 1:

		# Finding the mid of the array
		mid = len(arr)//2

		# Dividing the array elements
		L = arr[:mid]

		# into 2 halves
		R = arr[mid:]

		# Sorting the first half
		mergeSort(L)

		# Sorting the second half
		mergeSort(R)

		i = j = k = 0

		# Copy data to temp arrays L[] and R[]
		while i < len(L) and j < len(R):
			if L[i] < R[j]:
				arr[k] = L[i]
				i += 1
			else:
				arr[k] = R[j]
				j += 1
			k += 1

		# Checking if any element was left
		while i < len(L):
			arr[k] = L[i]
			i += 1
			k += 1

		while j < len(R):
			arr[k] = R[j]
			j += 1
			k += 1

# Code to print the list


def printList(arr):
	for i in range(len(arr)):
		print(arr[i], end=" ")
	print()




#Ejecucion

# Obtencion de los archivos generados
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

# Creacion del archivo para escritura de los items y el tiempo de ejecucion
file = open('mergeSort_python_time.txt', "w")
dicPaths = {}
for namefile in nameFiles_idx:
  # para obtencion de items   
  dicPaths.update({namefile:'../../1_preparacion_datos/generatedTestData/example_'+str(namefile)+".txt"})  

  arr=[]
  with open(dicPaths[namefile], "r") as f:
    for line in f:
        arr += [int(line.strip())]

  # declaracion del tiempo de ejecucion del algoritmo
  start = time.process_time()  
  mergeSort(arr)
  result = time.process_time() - start
  
  print("Se ordeno el array de tamanho " + str(len(arr)) + ": Tiempo tomado por el programa es... " + str(time.process_time() - start) + " segundos")

  # escribiendo en el archivo resultado
  file.write(str(namefile) + ' ' + str(result) +"\n")

file.close()


# This code is contributed by Mayank Khanna

