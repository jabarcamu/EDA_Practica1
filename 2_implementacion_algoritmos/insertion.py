# Python program for implementation of Insertion Sort
import sys
import time
import os
from tqdm import tqdm

# Function to do insertion sort
def insertionSort(arr):
 
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
 
        key = arr[i]
 
        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key 
 
#Initial State
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

file = open('insertionSort_time.txt', "w")
dicPaths = {}
for namefile in tqdm(nameFiles_idx):
  dicPaths.update({namefile:'generatedTestData/example_'+str(namefile)+".txt"})
  #create specific file

  arr=[]
  with open(dicPaths[namefile], "r") as f:
    for line in f:
        arr += [int(line.strip())]

  start = time.process_time()

  insertionSort(arr)

  # Driver code to test above
  result = time.process_time() - start
  file.write(str(result) +"\n")
  print("\n Sorted array")
  print(time.process_time() - start)

file.close()
#for i in range(len(arr)):
#    print ("% d" % arr[i])
 
# This code is contributed by Mohit Kumra