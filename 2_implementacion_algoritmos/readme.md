# Implementacion de Codigo
Para cada uno de los algoritmos de ordenamiento

en cada carpeta la ejecucion de cada algoritmo sera el siguiente

- Para C++ (por ejemplo desde carpeta cpp)
	 g++ insertion.cpp -std=c++14
	./a.out	

- Para Java (por ejemplo desde carpeta java)
	javac InsertionSort.java
	java InsertionSort
- Para Python
	python insertion.py


A continuacion se muestra una pequeña explicacion de algunos algoritmos

Insertion Sort:

Ordena un Array por el concepto de mano de cartas o barajas, inicia iterando tomando la primera carta, como comparacion inicial, mientras se vaya tomando un elemento siguiente siempre se comparara respecto al ultimo ordenado para que asi pueda ubicarce en la posicion en la que le corresponde.

Selection Sort:

Ordena un Array de manera repetida buscando el minumo elemento (considerando el orden ascendente) desde la parte desornada y poniendolo al principio. El algoritmo mantiene dos subarrays en el array implementado para que vaya iterando en completitud la longitud de todo el arreglo principal.


Ejecucion del Codigo y Pruebas

Bubble Sort: 

* C++
	- Elegir un IDE de codigo C++ (que incluya el compilador)
	- Crear un Proyecto de C++ o File .cpp
	- Copiar el codigo "codigo_bubble_sort.cpp" (ponerlo como ejecucion principal)
	- En la misma carpeta del codigo ingresar los .txt a ordenar
	- La salida se mostrará en consola del C++
	
* Python
	- Elegir un IDE de codigo Python (que incluya el compilador)
	- Crear un Proyecto de Phyton 2.7 o File .py
	- Copiar el codigo "codigo_bubble_sort.py" (ponerlo como ejecucion principal)
	- En la misma carpeta del codigo ingresar los .txt a ordenar
	- La salida se mostrará en consola del Python
	
* Java
	- Elegir un IDE de codigo Java (que incluya el compilador)
	- Crear un Proyecto de Java o File .java
	- Copiar el codigo "codigo_bubble_sort.java" (ponerlo como ejecucion principal)
	- En la misma carpeta del proyecto ingresar los .txt a ordenar
	- La salida se mostrará en consola del Java



# Algoritmo de ordenamiento - Counting Sort
```
counting-sort(A,B,k)
    for i <- 0 to k
        do C[i] <- 0

    for j <- 1 to length[A]
        do C[A[j]] <- C[A[j]] + 1
    
    for i <- 1 to k
        do C[i] <- C[i] + C[i - 1]
    
    for j <- length[A] to downto 1
        do B[C[A[j]]] <- A[j]
           C[A[j]] <- C[A[j]] - 1 
```

# Algoritmo de ordenamiento - Merge Sort
```
MergeSort(A,l,r)
    If r > l
        1. Encontrar el punto medio para dividir el arreglo en dos mitades
            middle m = l + (r - l)/2
        2. Llamar a mergeSort para la mitad izquierda
            call mergeSort(A,l,m)
        3. Llamar a mergeSort para la mitad derecha
            call mergeSort(A,m+1,r)
        4. Combinar las mitades ordenadas de los pasos 2 y 3
            call merge(A,l,m,r)
merge(A,l,m,r)

    n1 <- m - l + 1; 
	n2 <- r - m; 

	L[n1], R[n2];
	
    for i <- 0 to n1
        do L[i] <- A[l+i]

    for j <- 0 to n2
        do R[j] <- A[m+i+j]

	i<-0
    j<-0
    k<-l
		
	while i < n1 AND j < n2 do
		if L[i] <= R[j]
			arr[k] = L[i];
			i <- i + 1;		
		else 
			arr[k] = R[j];
			j <- j + 1;
		k <- k + 1;	
	
	while i < n1 do
		arr[k] <- L[i];
		i <- i + 1;
		k <- k + 1;
		
	while j < n2) 
		arr[k] <- R[j];
		j <- j + 1;
		k <- k + 1;
```