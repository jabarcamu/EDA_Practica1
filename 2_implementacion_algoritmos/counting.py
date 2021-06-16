
# a = lista no ordenada, b = lista ordenada, k = valor maximo de la lista
def counting_sort(a, k):
	# acumula los valores repetidos de la lista no ordenada
	c = []
	         
	# mismo tamaño de la lista no ordenada
	b = [0] * len(a)
	
	# inicializando los contadores a 0
	for x in range(k + 1):
		c.append(0)    
	
	# contando los valores repetidos
	for x in range(len(a)):
		c[a[x]] = c[a[x]] + 1
	
	# acumulando los repetidos para las posiciones
	for x in range(1, len(c)):
		c[x] = c[x] + c[x-1]	

	# ubicando los valores en sus respectivos indices
	for x in range(len(a) - 1, -1,-1):
		# asignamos el valor en la posicion ordenada
		b[c[a[x]] - 1] = a[x]
		# descontamos en 1 al valor acumulado(posicion correcta)
		c[a[x]] = c[a[x]] - 1
	return b

lista = [2,5,3,0,2,3,0,3]
print(counting_sort(lista, 5))