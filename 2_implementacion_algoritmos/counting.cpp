#include <iostream>
#include <vector>
#include <string>

using namespace std;

// a = lista no ordenada, k = valor maximo de la lista
vector<int> counting_sort(vector<int> a, int k){
     
    // acumula los valores repetidos
    vector<int> c; 
    // arreglo ordenado, mismo tamaño del original
    vector<int> b;
    // mismo tamaño de la lista no ordenada
    b.assign(a.size(), 0);

    // inicializando los contadores con 0
    for (int i = 0; i <= k; i++)
    {        
        c.push_back(0);
    }

    // contando la cantidad de valores repetidos
    for (int i = 0; i < a.size(); i++)
    {        
        c[a.at(i)] = c[a.at(i)] + 1;
    }

    // acumulando los repetidos para identificar las posiciones
    for (int i = 1; i < c.size(); i++)
    {     
        c[i] = c[i] + c[i - 1];
    }

    // ubicando 
    for (int i = a.size() - 1; i >= 0; i--)
    {
        // asignamos el valor en la posicion ordenada
        b[c[a[i]] - 1] = a[i];
        // descontamos en 1 al valor acumulado(posicion correcta)
        c[a[i]] = c[a[i]] - 1; 
    }
    
    return b;
}
int main()
{   
   vector<int> list{ 2,5,3,0,2,3,0,3 };      
   vector<int> list_sort = counting_sort(list, 5);    
   for (int i = 0; i < list_sort.size(); i++)
   {
       /* code */
       cout<<list_sort.at(i)<<endl;
   }
   
}
