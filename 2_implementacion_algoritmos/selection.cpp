// C++ program for implementation of selection sort
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

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
    myfile.open ("selectionSort_cpp_time.txt");
 
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

        int n = sizeof(arr)/sizeof(arr[0]); 
        

        clock_t start, end;
        start = clock();

        selectionSort(arr, n);
    
        end = clock();
    
        
        //printArray(arr, n);
    
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