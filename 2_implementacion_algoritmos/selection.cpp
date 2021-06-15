#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    //int arr[] = {64, 25, 12, 22, 11};    

    ifstream infile1("generatedTestData/example_100.txt");
 
    string linea;
    int size = 0;
    while (getline(infile1, linea))
    {
        istringstream iss(linea);        
        size++;
    }
 
    ifstream infile2("generatedTestData/example_100.txt");

    int arr[size];
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

    int n = sizeof(arr)/sizeof(arr[0]);  

    clock_t start, end;
    start = clock();

    selectionSort(arr, n);
 
    end = clock();
 
    cout << "Sorted array: \n";
    printArray(arr, n);
 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n Time taken by program is : " << fixed
         << time_taken << setprecision(8);
    cout << " sec " << endl;
 
    return 0;

}