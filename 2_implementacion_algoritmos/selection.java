%%writefile SelectionSort.java

// Java program for implementation of Selection Sort

import java.io.*;
import java.util.ArrayList; 

class SelectionSort
{
    void sort(int arr[])
    {
        int n = arr.length;
 
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
 
            // Swap the found minimum element with the first
            // element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
 
    // Prints the array
    void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
 
    // Driver code to test above
    public static void main(String args[]) throws IOException
    {
        try
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

            SelectionSort ob = new SelectionSort();
            //int arr[] = {64,25,12,22,11};
            ob.sort(arr);
            System.out.println("Sorted array");
            ob.printArray(arr);      
        }
        catch (IOException ex)  
        {
            // insert code to run when exception occurs
        }
        
    }
}
/* This code is contributed by Rajat Mishra*/