import numpy as np
import sys
import time
import os
from tqdm import tqdm


def heapify(arr, n, i):
    largest = i
    l = 2*i+1
    r = 2*i+2

    #Cada 3 valores acorde al n como limite de heapify
    #y acorde al valor i como actual raiz (que siempre debe ser mayor)
    #en caso que la raiz no sea el mayor si no...

    #el hijo izquierdo es mayor y respeta limite heapify
    if l < n and arr[largest] < arr[l]:
        largest = l

    #si ya cumplio la 1er condicion entonces largest es actualizado 
    #y se usa este como nuevo valor para evaluarlo con el hijo derecho

    #el hijo derecho es mayor y respeta limite heapify
    if r < n and arr[largest] < arr[r]:
        largest = r

    #si hubo cambios (actualizar y llamada recursiva con nueva posicion largest)
    if largest != i:
        arr [i], arr[largest] = arr[largest], arr[i]
        heapify(arr,n,largest)

def heapsort(arr):

    n = len(arr)
    #construir un maxheap
    #a partir de la mitad hacia atras y siempre con el mismo n(limite heapify)
    #se "ordenan los valores" haciendo que los mayores vayan al inicio del arreglo
    for i in range(n//2 -1, -1, -1):
        heapify(arr,n,i)

    #extraccion de elementos
    #ahora intercambiamos de acuerdo al pivote "i" que siempre ira reduciendose
    #hasta el segundo elemento

    #aplicamos heapify un limite heapify(n) progresivamente mas pequenho
    #ya que cada elemento intercambiado es extraido como el mayor elemento(raiz)
    #y van al final del array

    #asi quedarian ordenados de manera ascendente
    for i in range(n-1,0,-1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr,i,0)

#Ejecucion

# Obtencion de los archivos generados
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

# Creacion del archivo para escritura de los items y el tiempo de ejecucion
file = open('heapsort_python_time.txt', "w")
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
  heapsort(arr)  
  result = time.process_time() - start
  
  print("Se ordeno el array de tamanho " + str(len(arr)) + ": Tiempo tomado por el programa es... " + str(time.process_time() - start) + " segundos")

  # escribiendo en el archivo resultado
  file.write(str(namefile) + ' ' + str(result) +"\n")

file.close()
