
# Algoritmo de ordenamiento - COUNTING SORT

import numpy as np
import sys
import time
import os
from tqdm import tqdm


# retorna el maximo valor de un arreglo de numeros
def maxValueInArray(lista, sizeList):
	
	max = 0
	# inicializando los contadores a 0
	for x in range(sizeList):
		max = max if max >= lista[x] else lista[x] 
	return max

# a = arreglo no ordenado, k = valor maximo del arreglo
def counting_sort(a, k):
	# temporal para acumular valores repetidos
	c = []
	         
	# arreglo ordenado para retornar, mismo tamanho del arreglo principal.
	b = [0] * len(a)
	
	# inicializando los contadores a 0
	for x in range(k + 1):
		c.append(0)    
	
	# contando los valores repetidos
	for x in range(len(a)):
		c[a[x]] = c[a[x]] + 1
	
	# acumulando los repetidos para las posiciones(indices del arreglo)
	for x in range(1, len(c)):
		c[x] = c[x] + c[x-1]	

	# ubicando los valores en sus respectivos indices
	for x in range(len(a) - 1, -1,-1):
		# asignamos el valor en la posicion ordenada
		b[c[a[x]] - 1] = a[x]
		# descontamos en 1 al valor acumulado(posicion correcta)
		c[a[x]] = c[a[x]] - 1
	return b


#Ejecucion

# Obtencion de los archivos generados
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

# Creacion del archivo para escritura de los items y el tiempo de ejecucion
file = open('countingSort_python_time.txt', "w")
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
  counting_sort(arr, maxValueInArray(arr, len(arr)))
  result = time.process_time() - start
  
  print("Se ordeno el array de tamanho " + str(len(arr)) + ": Tiempo tomado por el programa es... " + str(time.process_time() - start) + " segundos")

  # escribiendo en el archivo resultado
  file.write(str(namefile) + ' ' + str(result) +"\n")

file.close()