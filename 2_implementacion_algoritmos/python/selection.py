#Python - SelectionSort - Implementacion
import numpy as np
import sys
import time
import os
from tqdm import tqdm

# Funcion para ordenar un array usando SelectionSort 
def selectionSort(A):
  # Recorrer todo el tamanho del array
  for i in range(len(A)):
     
    # Encontrar el minimo elemento en el array desordenado    
    min_idx = i
    for j in range(i+1, len(A)):
        if A[min_idx] > A[j]:
            min_idx = j
             
    # Intercambiar el elemento minimo encontrado con el primer elemento    
    A[i], A[min_idx] = A[min_idx], A[i]

#Ejecucion

# Obtencion de los archivos generados
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

# Creacion del archivo para escritura de los items y el tiempo de ejecucion
file = open('selectionSort_python_time.txt', "w")
dicPaths = {}
for namefile in tqdm(nameFiles_idx):
  # para obtencion de items
  dicPaths.update({namefile:'../../1_preparacion_datos/generatedTestData/example_'+str(namefile)+".txt"})
  
  A=[]
  with open(dicPaths[namefile], "r") as f:
    for line in f:
        A += [int(line.strip())]

  # declaracion del tiempo de ejecucion del algoritmo
  start = time.process_time()
  selectionSort(A)  
  result = time.process_time() - start

  print("Se ordeno el array de tamanho " + str(len(A)) + " :")
  print( "\n Tiempo tomado por el programa es: " + str(time.process_time() - start) )

  # escribiendo en el archivo resultado
  file.write(str(namefile) + ' ' + str(result) +"\n")
  
file.close()
