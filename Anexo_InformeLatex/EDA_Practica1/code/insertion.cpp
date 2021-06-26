// C++  Insertion Sort - Implementacion
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
 
/* Funcion para ordenar un array usando InsertionSort */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    //Partir desde 1 hasta len(arr),tamanho
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* 
            Mover los elementos de arr[0..i-1] que son
            mayores que el valor de key, a una posicion 
            adelante de su posicion actual
        */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// Funcion para imprimir un array de tamaño n 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    myfile.open ("insertionSort_cpp_time.txt");

    for (int k = 0; k < generate.size(); k++)
    {
        // para obtencion la cantidad de items
        ifstream infile1("../../1_preparacion_datos/generatedTestData/example_" + to_string(generate[k]) + ".txt");
    
        string linea;
        int size = 0;
        while (getline(infile1, linea))
        {
            istringstream iss(linea);        
            size++;
        }        
    
        // Obtencion de los items insertados a partir del tamanho ya obtenido anteriormente
        ifstream infile2("../../1_preparacion_datos/generatedTestData/example_" + to_string(generate[k]) + ".txt");
        
        int arr[size]; //insertando el tamanho del array
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
        insertionSort(arr, n);
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