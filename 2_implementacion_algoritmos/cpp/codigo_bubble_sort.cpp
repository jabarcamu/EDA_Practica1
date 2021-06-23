#include <iostream>
#include <string>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>


using namespace std;

int main() {

    int tam = 21;//21;
    int archivos[] = {100, 500, 1000, 2000, 3000, 4000,
                        5000, 6000, 7000, 8000, 9000,
                        10000, 20000, 30000, 40000, 50000,
                        60000, 70000, 80000, 90000, 100000};

    //*** recorrer archivos
    for(int indx=0; indx<tam; indx++){

        //*** abrir archivo
        string nombreArchivo = "";
        nombreArchivo.append("Random\\example_").append(to_string(archivos[indx])).append(".txt");
        ifstream archivo(nombreArchivo.c_str());

        //** RECORRER TXT Y RECOLECTAR DATOS
        string linea;
        std::vector<int> data;
        int n=0;
        while (getline(archivo, linea)) {
            data.push_back(std::stoi(linea));
            n++;
        }
        int arr[n];
        for (int i=0; i<data.size(); i++){
            arr[i]=data[i];
        }

        //** BUBBLE SORT Y TIEMPO
        int i, j, temp;
        auto t1 = std::chrono::high_resolution_clock::now();
        for(i = 0; i<n; i++) {
           for(j = i+1; j<n; j++){
              if(arr[j] < arr[i]) {
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
              }
           }
        }

        //** IMPRIMIR TIEMPO
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = t2 - t1;
        float miliseg = (float)(elapsed.count());
        cout<<archivos[indx]<<","<<setprecision(4)<<miliseg<<endl;

    }

	return 0;
}

