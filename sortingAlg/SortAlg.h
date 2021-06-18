#ifndef sortalg_h
#define sortalg_h

#include "algorithms/heapsort.h"

#include <string>
#include <iostream> //console
#include <bits/stdc++.h> //memset
#include <fstream> //archivos
#include <map>
using namespace std;


class SortAlg
{
	private:
		int arrayint[500];
		
	public:
		SortAlg();
		void genDicNumeroItems();
		void assignDefaultValues();
		void loadTestData();
		int* getArray(); 
		void printArray(int n);	

};

#endif
