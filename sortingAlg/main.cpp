#include "algorithms/heapsort.h"
#include "SortAlg.h"


using namespace std;
int main(){
    	SortAlg sortAlg;
	sortAlg.genDicNumeroItems();
	sortAlg.assignDefaultValues();
	
	int **testData = sortAlg.getTestData();
	vector<int> indTest = sortAlg.getIndTest();	
	Heapsort algHeapSort;
	ofstream ofs;
	string nameOutputFile="";
	//Aplicar Heapsort y ver el array afectado
	//iterate file by file (21 cases)
	for(int numtest = 0; numtest < indTest.size(); ++numtest){
		//apply heapsort for every test file
		cout<<"Numtest: "<< numtest << " Nro de casos: "<<indTest[numtest] << endl;
		algHeapSort.heapsort(testData[numtest],indTest[numtest]);
		nameOutputFile = sortAlg.getNameFileBase() + to_string(indTest[numtest]) + "sorted.txt";
		ofs.open(nameOutputFile,ofstream::out);
		for(int numSorted=0; numSorted < indTest[numtest]; ++numSorted){
			if(ofs.is_open()){
				ofs << testData[numtest][numSorted] << " ";
			}else{
				cout << "No puede crear archivo de escritura"<<endl;
			}
		}
		ofs.close();

		//cout << "NameOutputFile:"<< nameOutputFile << endl;
		
	}
	//sortAlg.printTestData();
	return 0;
}
