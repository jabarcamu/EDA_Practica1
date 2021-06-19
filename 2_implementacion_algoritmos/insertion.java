import java.io.*;
import java.lang.*;
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
        
        ArrayList<Integer> generate = new ArrayList<Integer>(); 
            generate.add(100);
            generate.add(500);
            for(int i=1000 ; i < 10000 ; i+=1000) {
                generate.add(i);
            }
            for(int i=10000 ; i < 100001 ; i+=10000) {
                generate.add(i);
            }

            
         
            PrintWriter writer = new PrintWriter("insertionSort_java_time.txt", "UTF-8");

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

                InsertionSort ob = new InsertionSort();

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
} /* This code is contributed by Rajat Mishra. */