%%writefile InsertionSort.java

import java.io.*;
import java.util.ArrayList; 

// Java program for implementation of Insertion Sort
class InsertionSort {
    /*Function to sort array using insertion sort*/
    void sort(int arr[])
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
 
            /* Move elements of arr[0..i-1], that are
               greater than key, to one position ahead
               of their current position */
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
 
    /* A utility function to print array of size n*/
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
 
        System.out.println();
    }
 
    // Driver method
    public static void main(String args[]) throws IOException
    {
        ArrayList<Integer> lista = new ArrayList<Integer>();
         
        String file = "generatedTestData/example_100.txt";
        BufferedReader bufferedReader = new BufferedReader(new FileReader(file));

        String curLine;
        while ((curLine = bufferedReader.readLine()) != null){
            //process the line as required
            //System.out.println(curLine);
            int num = Integer.parseInt(curLine);
            lista.add(num);
        }
        bufferedReader.close();
      
        int size = lista.size();
      
        System.out.println("Sorted array" + size);
      
        int[] arr = new int[size];
        for(int i=0; i < lista.size(); i++) {
            arr[i] = lista.get(i);
        }
 
        InsertionSort ob = new InsertionSort();
        ob.sort(arr);
 
        printArray(arr);
    }
} /* This code is contributed by Rajat Mishra. */