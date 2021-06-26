
// Fuente : https://www.geeksforgeeks.org/merge-sort/
// This code is contributed by Mayank Tyagi

// Algoritmo de ordenamiento MERGE SORT - divide y conquistaras

#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// arr, arreglo de numeros
// l, indice del limite inferior del arreglo
// m, indice medio entre el limite inferior l y superior r, del arreglo
// r, indice del limite superior del arreglo
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1; // cantidad de elementos del arreglo izquierdo.
	int n2 = r - m; // cantidad de elementos del arreglo derecho.

	// creacion de los arreglos temporales izquierdo y derecho respectivamente.
	int L[n1], R[n2];

	// copia de los valores en el arreglo izquierdo(arreglo esta ordenado)
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	// copia de los valores en el arreglo derecho(arreglo esta ordenado)
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];	

	// indice para el arreglo izquierdo
	int i = 0;

	// indice para el arreglo derecho
	int j = 0;

	// indice para el arreglo ordenado final
	int k = l;

	// copiar elementos en el arreglo principal, con elementos del arreglo izquierdo y/o derecho.
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// copiar elementos en el arreglo principal, con elementos del arreglo izquierdo(restantes)
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// copiar elementos en el arreglo principal, con elementos del arreglo derecho(restantes)
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


// arr, arreglo no ordenado de numeros.
// l, indice inferior del arreglo
// r, indice superior del arreglo
void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return; // retorno de la recursividad(paso base)
	}
	int m =l+ (r-l)/2; // calculando el indice del punto medio del arreglo
	mergeSort(arr,l,m); // llamada recursiva del arreglo izquierdo
	mergeSort(arr,m+1,r); // llamada recursiva del arreglo derecho
	merge(arr,l,m,r); // combinar arreglo izquierdo y derecho
}

// imprimir arreglo
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";			
}

int main()
{
	

	// generar los n valores de numeros(100, 500, ..., 100000)
    vector<int> generate; 
    generate.push_back(100);
    generate.push_back(500);

    for(int i=1000 ; i < 10000 ; i+=1000) {
        generate.push_back(i);
    }
    for(int i=10000 ; i < 100001 ; i+=10000) {
        generate.push_back(i);
    }


    // archivo para alamacenar los tiempos de ejecucion
    ofstream myfile;
    myfile.open ("mergeSort_cpp_time.txt");

    for (int k = 0; k < generate.size(); k++)
    {
        // carga de numeros alearios generados para cada caso de prueba       
        ifstream infile2("../../1_preparacion_datos/generatedTestData/example_" + to_string(generate[k]) + ".txt");
        
        int arr[generate[k]]; // creando el arreglo para los n valores de numeros
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
			  
        // calculando el tiempo de ejecucion del algoritmo.
        clock_t start, end;
        start = clock();    
        mergeSort(arr, 0, n - 1);
        end = clock();
		
        // tiempo de ejecucion obtenido
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    
        cout << "Se ordeno el array de tamanho " + to_string(n) + " :";    
        cout << "\n Tiempo tomado por el programa es: " << fixed
             << time_taken << setprecision(8);
        cout << " segundos " << endl;

        // guardando resultados de ejecucion del algoritmo para cada caso de prueba
        myfile << generate[k] << " "; 
        myfile << fixed << time_taken;    
        myfile << "\n";
    }

    myfile.close();

}


