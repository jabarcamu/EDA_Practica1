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