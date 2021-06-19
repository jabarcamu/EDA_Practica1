%%writefile SelectionSort.java

// Java program for implementation of Selection Sort

import java.io.*;
import java.lang.*;
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
       
            ArrayList<Integer> generate = new ArrayList<Integer>(); 
            generate.add(100);
            generate.add(500);
            for(int i=1000 ; i < 10000 ; i+=1000) {
                generate.add(i);
            }
            for(int i=10000 ; i < 100001 ; i+=10000) {
                generate.add(i);
            }

            
         
            PrintWriter writer = new PrintWriter("selectionSort_java_time.txt", "UTF-8");
         
            generate.forEach((n) -> {
                ArrayList<Integer> lista = new ArrayList<Integer>();
            
                String file = "generatedTestData/example_"+ n.toString() +".txt";
                try{
                    BufferedReader bufferedReader = new BufferedReader(new FileReader(file));

                    String curLine;
                    while ((curLine = bufferedReader.readLine()) != null){
                        //process the line as required
                        //System.out.println(curLine);
                        int num = Integer.parseInt(curLine);
                        lista.add(num);
                    }
                    bufferedReader.close(); 
                }
                catch (IOException ex)  
                {
                    // insert code to run when exception occurs
                }
            
                int size = lista.size();
            
                System.out.println("Sorted array" + size);
            
                int[] arr = new int[size];
                for(int i=0; i < lista.size(); i++) {
                    arr[i] = lista.get(i);
                }

                SelectionSort ob = new SelectionSort();

                //int arr[] = {64,25,12,22,11};
                double startTime = System.nanoTime();
                ob.sort(arr);
                double endTime = System.nanoTime();
            
                double duration = (endTime - startTime)/1000000;
                System.out.println("Sorted array");
                //ob.printArray(arr);      
                writer.println( n.toString() + ' ' + duration);
            });            
         
            writer.close();   

        
    }
}
/* This code is contributed by Rajat Mishra*/