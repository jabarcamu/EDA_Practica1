// C++ program for insertion sort
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
 
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
/* Driver code */
int main()
{
    //int arr[] = { 12, 11, 13, 5, 6 };
 
    vector<int> generate; 
    generate.push_back(100);
    generate.push_back(500);

    for(int i=1000 ; i < 10000 ; i+=1000) {
        generate.push_back(i);
    }
    for(int i=10000 ; i < 100001 ; i+=10000) {
        generate.push_back(i);
    }
    
    ofstream myfile;
    myfile.open ("insertionSort_cpp_time.txt");
 
    for (int k = 0; k < generate.size(); k++) {
 
        ifstream infile1("generatedTestData/example_" + to_string(generate[k]) + ".txt");
    
        string linea;
        int size = 0;
        while (getline(infile1, linea))
        {
            istringstream iss(linea);        
            size++;
        }
    
        ifstream infile2("generatedTestData/example_" + to_string(generate[k]) + ".txt");

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

        int n = sizeof(arr) / sizeof(arr[0]);
    
        clock_t start, end;
        start = clock();
    
        insertionSort(arr, n);

        end = clock();

        double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    
        cout << "Sorted array:";
    
        cout << "\n Time taken by program is : " << fixed
            << time_taken << setprecision(8);
        cout << " sec " << endl;

        //writting in the file
        myfile << generate[k] << " "; 
        myfile << fixed << time_taken;    
        myfile << "\n";

    }
 
    myfile.close();
 
    return 0;
}
 
// This is code is contributed by rathbhupendra