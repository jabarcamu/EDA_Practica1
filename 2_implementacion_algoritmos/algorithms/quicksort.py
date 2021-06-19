class QuickSort:
    def __init__(self):
        print("constructor")
    
    #Puntos de inicio y final y el ultimo elemento del array
    def partition(self,start, end, array):
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

    def quicksort(self,start, end, array):
        if (start < end):
            #p es el indice de particion, array[p] es el correcto lugar
            p = self.partition(start, end, array)

            #ordenar los elemento antes y despues del pivote
            self.quicksort(start, p-1, array)
            self.quicksort(p+1, end, array)

