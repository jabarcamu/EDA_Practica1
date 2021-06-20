// Java - Selection Sort - Implementacion
import java.io.*;
import java.lang.*;
import java.util.ArrayList; 

class SelectionSort
{
    /* Funcion para ordenar un array usando InsertionSort */
    void sort(int arr[])
    {
        int n = arr.length;
 
        // Mover uno por uno entre el limite del subarray desordenado
        for (int i = 0; i < n-1; i++)
        {
            // Encontrar el minimo elemento en el array desordenado
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
 
            // Intercambiar el elemento minimo encontrado con el primer elemento
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
    
    /* Funcion para imprimir el array */
    void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
 
    // Ejecucion
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
        PrintWriter writer = new PrintWriter("selectionSort_java_time.txt", "UTF-8");
        
        generate.forEach((n) -> {
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
        
            int[] arr = new int[size];
            for(int i=0; i < lista.size(); i++) {
                arr[i] = lista.get(i);
            }

            SelectionSort ob = new SelectionSort();
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