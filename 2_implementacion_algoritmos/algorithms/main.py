from heapsort import HeapSort
from quicksort import QuickSort
import time
import glob

heap_sort = HeapSort()
quick_sort = QuickSort()

print(glob.glob)

#Filling the array with testData
arr = []
with open("../generatedTestData/example_500.txt","r") as f:
    for line in f:
        arr.append(int(line))

#Opcion de Ordenamiento
sortSelected = input("Ingrese Tipo Ordenamiento:")

if (sortSelected == "0"):
    #Apply Heapsort algorithm
    startTime = time.time()
    heap_sort.heapsort(arr)
    print("heapsort take %s seconds"%(time.time() - startTime))
    print(arr)
elif (sortSelected == "1"):
    #Apply QuickSort algorithm
    startTime = time.time()
    quick_sort.quicksort(0,len(arr)-1,arr)
    print("heapsort take %s seconds"%(time.time() - startTime))
    print(arr)
