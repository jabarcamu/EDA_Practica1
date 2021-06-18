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


#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

class SortAlg
{
	private:
		//Carga de Datos
		int **testData;
		vector<int> vecIndTest;
		map<int,string> testPaths;
		map<string,string> mapPathDirs;
		string pathPlots = "PlotFiles/";
		string pathSortFiles = "SortFiles/";
		string pathBase = "generatedTestData/";
		string nameFileBase = "example_";
		int numDatos;	
		
				
		
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
		string getpathdirs(string keyPathDir);
		void writePlotFiles(map<int,string> &sortAlgs,int selectedSort);
		string showPlot(char const* cmd);
};

#endif
