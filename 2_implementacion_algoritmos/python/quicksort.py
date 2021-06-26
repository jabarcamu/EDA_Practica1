import numpy as np
import sys
import time
import os
from tqdm import tqdm


#Puntos de inicio y final y el ultimo elemento del array
def partition(start, end, array):
    #Inicializando indice del pivote inicial
    pivot_index = start
    pivot = array[pivot_index]

    #iterar hasta que el ptro de inicio cruce con el ptro final,
    #intercambiamos el pivote con el elemento sobre el ptro final
    while start < end:

        #incrementamos el ptro de inicio hasta que encuentre
        #un elemento mas grande que el pivote
        while start < len(array) and array[start] <= pivot:
            start += 1

        #decrementamos el puntero final hasta que que encuentre
        #un elemento menos que el pivote
        while array[end] > pivot:
            end -= 1

        #Si el start y end no se han cruzado, intercambiamos los números
        #del ptro start y end
        if (start < end):
            array[start], array[end] = array[end], array[start]

    #Cambiamos el pivote con el elemento sobre el ptro final
    #Esto colocal el pivote en el correcto lugar de orden
    array[end], array[pivot_index] = array[pivot_index], array[end]

    #retorna el ptro final para dividir el array en 2
    return end

def quicksort(start, end, array):
    if (start < end):
        #p es el indice de particion, array[p] es el correcto lugar
        p = partition(start, end, array)

        #ordenar los elemento antes y despues del pivote
        quicksort(start, p-1, array)
        quicksort(p+1, end, array)
    

#Ejecucion

# Obtencion de los archivos generados
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

# Creacion del archivo para escritura de los items y el tiempo de ejecucion
file = open('quicksort_python_time.txt', "w")
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
  quicksort(0,len(arr)-1,arr)  
  result = time.process_time() - start
  
  print("Se ordeno el array de tamanho " + str(len(arr)) + ": Tiempo tomado por el programa es... " + str(time.process_time() - start) + " segundos")

  # escribiendo en el archivo resultado
  file.write(str(namefile) + ' ' + str(result) +"\n")

file.close()

