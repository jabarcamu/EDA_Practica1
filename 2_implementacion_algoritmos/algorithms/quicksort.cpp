#include "quicksort.h"
#include <bits/stdc++.h>
#include <utility>
using namespace std;

Quicksort::Quicksort(){}

/* Toma el ultimo elemento como pivote,
   localiza el pivote en su correcta posicion en el array ordenado
   localiza los elemento mas pequeños a la izquierda del pivote
   localiza los elementos mas grande a la derecha del pivote
   */
int Quicksort::partition(int arr[], int low, int high)
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

void Quicksort::quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		//ordenar los elementos antes y despues del pivote
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi+1, high);
	}
}

void Quicksort::printArray(int arr[], int size)
{

	int i;
	for (i=0; i<size; i++)
		cout << arr[i] << " "; 
	cout << endl;
} 

/*
int main(){
	int arrayint[500];
	memset(arrayint,0,500);
	string line;
	std::ifstream ifs;
	ifs.open("generatedTestData/example_500.txt", std::ifstream::in);
	int idx = 0;
	if(ifs.is_open()){
		while(getline(ifs, line))
		{
			//cout << line << "\n";
			arrayint[idx] = stoi(line);
			idx++;
		}
		ifs.close();
		quicksort(arrayint, 0, 500-1);
		printArray(arrayint,500);

	}
	else cout << "No se pudo abrir el archivo";

	return 0;
}*/
