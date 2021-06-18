#ifndef sortalg_h
#define sortalg_h

#include "algorithms/heapsort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream> //console
#include <bits/stdc++.h> //memset
#include <fstream> //archivos
#include <map>
#include <vector>

using namespace std;

class SortAlg
{
	private:
		//Carga de Datos
		int **testData;
		vector<int> vecIndTest;
		map<int,string> testPaths;
		string pathBase = "generatedTestData/";
		string nameFileBase = "example_";
		int numDatos;	
		//Algoritmos
		
		//map<string,auto> sorts;
				
		
	public:
		SortAlg();
		void genDicNumeroItems();
		void assignDefaultValues();
		void applySorting(string nameSortAlg);
		//two time of lecture
		int** getTestData(); 
		void printTestData();
		int getNumDatos();	
		vector<int> getIndTest();
		string getNameFileBase();
};

#endif
