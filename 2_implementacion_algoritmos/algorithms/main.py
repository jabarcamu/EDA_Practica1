from heapsort import HeapSort
from quicksort import QuickSort

heap_sort = HeapSort()
quick_sort = QuickSort()


#Filling the array with testData
arr = []
with open("../generatedTestData/example_500.txt","r") as f:
    for line in f:
        arr.append(int(line))

#Opcion de Ordenamiento
sortSelected = input("Ingrese Tipo Ordenamiento:")

if (sortSelected == "0"):
    #Apply Heapsort algorithm
    heap_sort.heapsort(arr)
    print(arr)
elif (sortSelected == "1"):
    #Apply QuickSort algorithm
    quick_sort.quicksort(0,len(arr)-1,arr)
    print(arr)
