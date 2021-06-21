// Java program for implementation of Heap Sort
import java.io.*;
import java.lang.*;
import java.util.ArrayList; 
import java.util.Arrays;
import java.util.List;


class HeapSort {
    public void sort(int arr[])
    {
        int n = arr.length;
 
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
 
        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
 
            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
 
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    void heapify(int arr[], int n, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
 
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
 
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
 
        // If largest is not root
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
 
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
 
    /* A utility function to print array of size n */
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }


    /* Ejecucion */
    public static void main(String args[]) throws IOException
    {
	    // Obtencion de los archivos generados
	    ArrayList<Integer> generate = new ArrayList<Integer>(); 
	    generate.add(100);
	    generate.add(500);
	    for(int i=1000 ; i < 10000 ; i+=1000) {
		    generate.add(i);
	    }
	    for(int i=10000 ; i < 100001 ; i+=10000) {
		    generate.add(i);
	    }

	    // Creacion del archivo para escritura de los items y el tiempo de ejecucion
	    PrintWriter writer = new PrintWriter("heapsort_java_time.txt");

	    generate.forEach( (n) -> {

		    ArrayList<Integer> lista = new ArrayList<Integer>();
		    // Obtencion de los items insertados      
		    String file = "../../1_preparacion_datos/generatedTestData/example_"+ n.toString() +".txt";

		    try{
			    BufferedReader bufferedReader = new BufferedReader(new FileReader(file));

			    String curLine;
			    while ((curLine = bufferedReader.readLine()) != null){                    
				    int num = Integer.parseInt(curLine);
				    lista.add(num);
			    }

			    bufferedReader.close(); 
		    }
		    catch (IOException ex)  
		    {
			    System.out.println(ex.getMessage());
		    }

		    // solo para tener el numero de array, igualmente el valor ya es conocido
		    int size = lista.size();
		    
		    int[] arr = lista.stream().mapToInt(i -> i).toArray();


		    HeapSort ob = new HeapSort();
		    // declaracion del tiempo de ejecucion del algoritmo
		    double startTime = System.nanoTime();
		    ob.sort(arr);
		    double endTime = System.nanoTime();

		    // tiempo de ejecucion obtenido
		    double duration = (endTime - startTime)/1000000000;
		    System.out.println("Se ordeno el array de tamanho " + size + " :");
		    System.out.println("\n Tiempo tomado por el programa es: " + duration + " segundos");

		    writer.println( n.toString() + ' ' + duration);

	    });            

	    writer.close(); 
    }

}
