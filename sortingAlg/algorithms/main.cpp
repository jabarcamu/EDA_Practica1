#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "heapsort.h"
using namespace std;
int main(){
    int numTest = 100;
    cout << "Ingrese un Numero de Prueba: ";
    cin >> numTest;
    int arrayint[numTest];
    memset(arrayint,0,numTest);
    string line;
    std::ifstream ifs;
    ifs.open("../generatedTestData/example_"+to_string(numTest)+".txt", std::ifstream::in);
    int idx = 0;
    if(ifs.is_open()){
        while(getline(ifs, line))
        {
            //cout << line << "\n";
            arrayint[idx] = stoi(line);
            idx++;
        }
        ifs.close();
        Heapsort algoheap;

	algoheap.heapsort(arrayint,numTest);
        algoheap.printArray(arrayint,numTest);

    }
    else cout << "No se pudo abrir el archivo";
    cout << "Complete Sorting"<<endl;
    return 0;
}
