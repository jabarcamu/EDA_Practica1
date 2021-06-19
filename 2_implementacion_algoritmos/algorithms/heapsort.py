class HeapSort:
    def __init__(self):
        print("constructor")

    def heapify(self, arr, n, i):
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
            self.heapify(arr,n,largest)

    def heapsort(self,arr):
        n = len(arr)
        #construir un maxheap
        #a partir de la mitad hacia atras y siempre con el mismo n(limite heapify)
        #se "ordenan los valores" haciendo que los mayores vayan al inicio del arreglo
        for i in range(n//2 -1, -1, -1):
            self.heapify(arr,n,i)

        #extraccion de elementos
        #ahora intercambiamos de acuerdo al pivote "i" que siempre ira reduciendose
        #hasta el segundo elemento

        #aplicamos heapify un limite heapify(n) progresivamente mas pequeño
        #ya que cada elemento intercambiado es extraido como el mayor elemento(raiz)
        #y van al final del array

        #asi quedarian ordenados de manera ascendente
        for i in range(n-1,0,-1):
            arr[i], arr[0] = arr[0], arr[i]
            self.heapify(arr,i,0)

    def printArr(self,arr):
        txt = ""
        for i in range(len(arr)):
            txt  = txt + str(arr[i]) + " "
        print(txt)


