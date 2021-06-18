#include "SortAlg.h"

SortAlg::SortAlg(){}

void SortAlg::genDicNumeroItems(){
	vecIndTest.push_back(100);	
	vecIndTest.push_back(500);	
	for (int i=1000; i<=9000; i+=1000){
		vecIndTest.push_back(i);
			
	}
	for (int i=10000; i<=100000; i+=10000){
		vecIndTest.push_back(i);
			
	}
	
	//ToDo: modificalo con glob tambien	
	for(vector<int>::iterator it = vecIndTest.begin(); it != vecIndTest.end(); ++it){
		testPaths.insert(make_pair(*it,pathBase + nameFileBase + to_string(*it) + ".txt" ));
	}	

	
	/*for(auto &item : testPaths){
		cout << item.first << ":" << item.second << endl;
	}
	cout << "]\n";*/
	
		
}

void SortAlg::assignDefaultValues(){
	
	//ptros a referenciar lista de enteros
	testData = new int*[testPaths.size()];
	
	string line;
    	ifstream ifs;

	int i = 0;
	//iterate file by file on testData
	for(auto &item: testPaths){
		//inicializacion de lista de enteros	
		testData[i] = new int[item.first];

		ifs.open(item.second, std::ifstream::in);
    		int idx = 0;
    		if(ifs.is_open()){
			//iterate line by line inside of the file
        		while(getline(ifs, line))
        		{
            			//cout << line << "\n";
            			testData[i][idx] = stoi(line);
            			++idx;
        		}
        		ifs.close();
			//cout << "Termino la carga del archivo "<< to_string(i) << " " << item.first << endl;
		}
		else cout << "No se pudo abrir el archivo"<<endl;
		++i;
	}
	cout << "Terminada incializacion de datos"<<endl;
}

int** SortAlg::getTestData(){
	return testData;
}



void SortAlg::applySorting(string nameSortAlg){
		
}

void SortAlg::printTestData(){
	for (int i=0; i< vecIndTest[i]; ++i){
		cout << "Showing Test Data with " << to_string(vecIndTest[i]) << " datos" << endl;
		for(int j=0; j<vecIndTest[i]; ++j){
			//cout << testData[i][j] << " "; 
		}
	}
	cout << "Termino la carga de datos\n";
}

int SortAlg::getNumDatos(){
	if(vecIndTest.size()>0){
		return vecIndTest.size();	
	}
}

vector<int> SortAlg::getIndTest(){
	return vecIndTest;
}

string SortAlg::getNameFileBase(){
	return nameFileBase;
}
