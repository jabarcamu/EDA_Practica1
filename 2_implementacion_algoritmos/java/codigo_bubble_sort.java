/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package maestria_cc_edat;

import java.io.*;
import java.lang.*;
import java.util.ArrayList;

/**
 *
 * @author crisa
 */
public class Bubble_Sort {
    
    int tam = 21;
    int archivos[] = {100, 500, 1000, 2000, 3000, 4000,
                        5000, 6000, 7000, 8000, 9000,
                        10000, 20000, 30000, 40000, 50000,
                        60000, 70000, 80000, 90000, 100000};
    
    public Bubble_Sort(){}
    
    public void Ejecutar(){
        try {
          PrintWriter writer = new PrintWriter("tiempo_bubble_sort_java.txt");
          for(int indx=0; indx<archivos.length; indx++){
              Integer arr[] = extraer_data("../../1_preparacion_datos/generatedTestData/example_"+archivos[indx]+".txt").toArray(new Integer[0]);
              int n = arr.length;  
              int temp = 0, i = 0, j = 0;  
              long tie_ini = System.nanoTime();
              for(i=0; i < n; i++){  
                  for(j=1; j < (n-i); j++){  
                      if(arr[j-1] > arr[j]){  
                          //swap elements  
                          temp = arr[j-1];  
                          arr[j-1] = arr[j];  
                          arr[j] = temp;  
                      }  
                  }  
              }  
              long tie_fin = System.nanoTime();
              System.out.println(archivos[indx]+" "+((double)((double)tie_fin-(double)tie_ini)/1000000000));
              writer.println( archivos[indx] + " " + ((double)((double)tie_fin-(double)tie_ini)/1000000000));
              
          }
          writer.close();
        } catch(Exception e){System.out.println("err:"+e);}
        
    }
    
    public ArrayList<Integer> extraer_data(String archivo){
        ArrayList<Integer> data = new ArrayList<Integer>();
        try{
            String tex;
            FileReader fr = new FileReader(new File(archivo));
            BufferedReader br = new BufferedReader(fr);
            while((tex = br.readLine())!=null) {
                try{if(!tex.equals(""))data.add(Integer.parseInt(tex));}catch(Exception e){}
            }
            br.close();
        }catch(Exception e){System.out.println("err:"+e);}
        return(data);
    }

    /* Ejecucion */
    public static void main(String args[]) 
    {
        Bubble_Sort bubble = new Bubble_Sort();
     
        bubble.Ejecutar();
    }
}