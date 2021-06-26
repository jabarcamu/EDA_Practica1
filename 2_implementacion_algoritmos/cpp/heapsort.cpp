#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l < n) 
      if (l < n && arr[largest] < arr[l])
          largest = l;
    if (r < n)
      if (r < n && arr[largest] < arr[r])
          largest = r;

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n){
    
    for (int i=n/2-1; i>=0; i--)
        heapify(arr,n,i);
    for (int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}


void printArray(int arr[], int n){
	for (int i=0; i<n; i+=n/10)
      		cout << arr[i] << " ";
  	cout << "\n";   
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
    myfile.open ("heapsort_cpp_time.txt");

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
        heapsort(arr, n);
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
