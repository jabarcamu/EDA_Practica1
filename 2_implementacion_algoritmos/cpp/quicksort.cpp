#include <bits/stdc++.h>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;



/* Toma el ultimo elemento como pivote,
   localiza el pivote en su correcta posicion en el array ordenado
   localiza los elemento mas pequeños a la izquierda del pivote
   localiza los elementos mas grande a la derecha del pivote
   */
int partition(int arr[], int low, int high)
{
	//pivote
	int pivot  = arr[high]; 

	//indice del elemento mas pequenio e indica la correcta posicion del pivote encontrado
	int i  = (low - 1);

	for (int j = low; j <= high -1; j++)
	{
		//si el elemento es mas pequenio que el pivote
		if (arr[j] < pivot)
		{
			i++; //incrementamos el indice del elemento mas pequenio
			swap(arr[i], arr[j]); 
		}
	}
	swap(arr[i+1], arr[high]);
	return (i+1);
}

void quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		//ordenar los elementos antes y despues del pivote
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi+1, high);
	}
}
 
// Ejecucion
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
    myfile.open ("quicksort_cpp_time.txt");
 
    for (int k = 0; k < generate.size(); k++) {
 
        // Obtencion de los items insertados a partir del tamaño ya obtenido anteriormente    
        ifstream infile2("../../1_preparacion_datos/generatedTestData/example_" + to_string(generate[k]) + ".txt");

        int arr[generate[k]]; //insertando el tamaño del array
        int i=0;
        string line;
        while (getline(infile2, line))
        {
            istringstream iss(line);
            int a;
            if (!(iss >> a)) { break; } // error        
            arr[i] = a;
            i++;
        }

        // solo para tener el numero de array, igualmente el valor ya es conocido
        int n = sizeof(arr)/sizeof(arr[0]); 
        
        // declaracion del tiempo de ejecucion del algoritmo
        clock_t start, end;
        start = clock();

        quicksort(arr,0, n-1);
    
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
 
    return 0;

}
