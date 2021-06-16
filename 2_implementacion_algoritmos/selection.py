# Python program for implementation of Selection
# Sort
import sys
import time
import os
from tqdm import tqdm

'''
A = []
read = open("generatedTestData/example_100.txt", "r")
A = read.readlines()
B = []
for k in A:
    B += [int(k.strip())]
'''

# Function to do selection sort
def SelectionSort(A):
  # Traverse through all array elements
  for i in range(len(A)):
     
    # Find the minimum element in remaining
    # unsorted array
    min_idx = i
    for j in range(i+1, len(A)):
        if A[min_idx] > A[j]:
            min_idx = j
             
    # Swap the found minimum element with
    # the first element       
    A[i], A[min_idx] = A[min_idx], A[i]

#Initial State
nameFiles_idx = np.concatenate((np.arange(100,501,400),np.arange(1000,10000,1000),np.arange(10000,100001,10000)),axis=None)

file = open('selectionSort_time.txt', "w")
dicPaths = {}
for namefile in tqdm(nameFiles_idx):
  dicPaths.update({namefile:'generatedTestData/example_'+str(namefile)+".txt"})
  #create specific file

  A=[]
  with open(dicPaths[namefile], "r") as f:
    for line in f:
        A += [int(line.strip())]

  start = time.process_time()

  SelectionSort(A)
 
  # Driver code to test above
  result = time.process_time() - start
  file.write(str(result) +"\n")
  print("\n Sorted array")
  print(time.process_time() - start)
  
  #for i in range(len(A)):
  #    print("%d" %A[i])

file.close()
#end procedure