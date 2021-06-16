# Implementacion de Codigo
Para cada uno de los algoritmos de ordenamiento
// A = lista a ordenar
// B = retorno de lista ordenada
// k = valor maximo de la lista
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