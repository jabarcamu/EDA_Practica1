# Implementacion de Codigo Counting Sort
Para cada uno de los algoritmos de ordenamiento
A = lista a ordenar
B = retorno de lista ordenada
k = valor maximo de la lista

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


# Implementacion de Codigo Merge Sort

MergeSort(arr,l,r)
    If r > l
        1. Encontrar el punto medio para dividir el arreglo en dos mitades
            middle m = l + (r - l)/2
        2. Llamar a mergeSort para la mitad izquierda
            call mergeSort(arr,l,m)
        3. Llamar a mergeSort para la mitad derecha
            call mergeSort(arr,m+1,r)
        4. Combinar las mitades ordenadas de los pasos 2 y 3
            call merge(arr,l,n,r)