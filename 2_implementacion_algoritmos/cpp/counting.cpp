
// Algoritmo de ordenamiento - INSERTION SORT

#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// imprimir arreglo
void printArray(int arr[], size_t sizeList){    
    for (int i = 0; i < sizeList; i++) {        
        cout<< arr[i]<<" ";		
    }        
}
 // retorna el maximo valor de un arreglo de numeros enteros
int maxValueInArray(int list[], size_t sizeList) {
	int max = 0;
	for (int i = 0; i < sizeList; i++) {
		max = (max >= list[i]) ? max : list[i];
	}
	
	return max;
}

// A = lista no ordenada inicial.
// B = lista ordenada para retornar.
// k = valor maximo de la lista.
// sizeList = tamaño de la lista A
int *counting_sort(int A[], int B[], int k, size_t sizeList){
     
    // temporal para almacenar los conteos, inicialmente a 0
    int C[k + 1] = {0};         

    // contando los valores repetidos
    for (int i = 0; i < sizeList; i++) {        
        C[A[i]] = C[A[i]] + 1;
    }

    // acumulando los repetidos para las posiciones
    for (int i = 1; i < (k + 1); i++)
    {
        /* code */
        C[i] = C[i] + C[i - 1];
    }    

    // ubicando los valores en sus respectivos indices
    for (int i = (sizeList - 1); i >= 0; i--)
    {
        // asignamos el valor en la posicion ordenada
        B[C[A[i]] - 1] = A[i];
        // descontamos en 1 al valor acumulado(posicion correcta)
        C[A[i]] = C[A[i]] - 1; 
    }
    return B;
}

/* Ejecucion */
int main()
{
	// Obtencion de los archivos generados
    vector<int> generate; 
    generate.push_back(100);
    generate.push_back(500);

    for(int i=1000 ; i < 10000 ; i+=1000) {
        generate.push_back(i);
    }
    for(int i=10000 ; i < 100001 ; i+=10000) {
        generate.push_back(i);
    }


    // Creacion del archivo para escritura de los items y el tiempo de ejecucion
    ofstream myfile;
    myfile.open ("countingSort_cpp_time.txt");

    for (int k = 0; k < generate.size(); k++)
    {
        // Obtencion de los items insertados a partir del tamanho ya obtenido anteriormente        
        ifstream infile2("../../1_preparacion_datos/generatedTestData/example_" + to_string(generate[k]) + ".txt");
        
        int arr[generate[k]]; //insertando el tamanho del array
        int i=0;
        string line;
        while (getline(infile2, line))
        {
            istringstream iss(line);
            int a;
            if (!(iss >> a)) { break; }			
            arr[i] = a;
            i++;
        }
		
        // solo para tener el numero de array, igualmente el valor ya es conocido
        int n = sizeof(arr) / sizeof(arr[0]);		     
		int B[generate[k]]={0};
		int maxValue = maxValueInArray(arr, n);	  		
			  
        // declaracion del tiempo de ejecucion del algoritmo
        clock_t start, end;
        start = clock();    
        counting_sort(arr,B,maxValue,generate[k]);
        end = clock();
		
        // tiempo de ejecucion obtenido
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    
        cout << "Se ordeno el array de tamanho " + to_string(n) + " :";    
        cout << "\n Tiempo tomado por el programa es: " << fixed
             << time_taken << setprecision(8);
        cout << " segundos " << endl;

        //escribiendo en el archivo resultado
        myfile << generate[k] << " "; 
        myfile << fixed << time_taken;    
        myfile << "\n";
    }

    myfile.close();
}