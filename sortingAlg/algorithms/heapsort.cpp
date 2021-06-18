#include "heapsort.h"
#include <iostream>
using namespace std;

void Heapsort::heapify(int arr[], int n, int i)
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

void Heapsort::heapsort(int arr[], int n){
    
    for (int i=n/2-1; i>=0; i--)
        heapify(arr,n,i);
    for (int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}


Heapsort::Heapsort(){}
/*int Heapsort::getNum(){
	return num;
}

Heapsort::Heapsort(int n): num(n){}
*/
