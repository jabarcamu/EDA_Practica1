
// Fuente : https://www.geeksforgeeks.org/merge-sort/

// C++ program for Merge Sort

#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

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

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;//returns recursively
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";			
}

// Driver code
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
    myfile.open ("mergeSort_cpp_time.txt");

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
			  
        // declaracion del tiempo de ejecucion del algoritmo
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

        //escribiendo en el archivo resultado
        myfile << generate[k] << " "; 
        myfile << fixed << time_taken;    
        myfile << "\n";
    }

    myfile.close();

}

// This code is contributed by Mayank Tyagi
