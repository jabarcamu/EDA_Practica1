#Python - InsertionSort - Implementacion
import numpy as np
import sys
import time
import os
from tqdm import tqdm

# Funcion para ordenar un array usando InsertionSort 
def insertionSort(arr):
 
    # Partir desde 1 hasta len(arr),tamanho
    for i in range(1, len(arr)):
 
        key = arr[i]
 
        # Mover los elementos de arr[0..i-1] que son
        # mayores que el valor de key, a una posicion 
        # adelante de su posicion actual
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key 

#Ejecucion

# Obtencion de los archivos generados
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000)),np.arange(10000,100001,10000),axis=None)

# Creacion del archivo para escritura de los items y el tiempo de ejecucion
file = open('insertionSort_python_time.txt', "w")
dicPaths = {}
for namefile in tqdm(nameFiles_idx):
  # para obtencion de items
  dicPaths.update({namefile:'../../1_preparacion_datos/generatedTestData/example_'+str(namefile)+".txt"})  

  arr=[]
  with open(dicPaths[namefile], "r") as f:
    for line in f:
        arr += [int(line.strip())]

  # declaracion del tiempo de ejecucion del algoritmo
  start = time.process_time()
  insertionSort(arr)  
  result = time.process_time() - start
  
  print("Se ordeno el array de tamanho " + str(len(arr)) + " :")
  print( "\n Tiempo tomado por el programa es: " + str(time.process_time() - start) )

  # escribiendo en el archivo resultado
  file.write(str(namefile) + ' ' + str(result) +"\n")

file.close()
