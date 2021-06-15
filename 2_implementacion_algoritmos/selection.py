# Python program for implementation of Selection
# Sort
import sys
import time

'''
A = []
read = open("generatedTestData/example_100.txt", "r")
A = read.readlines()
B = []
for k in A:
    B += [int(k.strip())]
'''

A=[]
with open('generatedTestData/example_100.txt', "r") as f:
    for line in f:
        A += [int(line.strip())]
start = time.process_time()
# your code here    

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
 
# Driver code to test above
print(time.process_time() - start)
print ("Sorted array")
#for i in range(len(A)):
#    print("%d" %A[i])