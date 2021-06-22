#include "algorithms/heapsort.h"
#include "algorithms/quicksort.h"
#include "SortAlg.h"
#include <sys/time.h>



using namespace std;
using namespace std::chrono;
void mainMenu(){
	cout << "************************"<<endl;
	cout << "(1) HeapSort     	 "<<endl;
	cout << "(2) QuickSort		 "<<endl;
	cout << "************************"<<endl;
}


int main(){
	//manage testData loading
    	SortAlg sortAlg;
	sortAlg.genDicNumeroItems();
	sortAlg.assignDefaultValues();
		
	int **testData = sortAlg.getTestData();
	vector<int> indTest = sortAlg.getIndTest();
	vector<int> execTime(indTest.size(),0);	
	map<int,string> sortAlgs = {
		{1, "_by_heapsort"},
		{2, "_by_quicksort"}
	};

	//Sorting algorithms
	Heapsort algHeapSort;
	Quicksort algQuickSort;
	
	string nameOutputFile="";	
	int sortSelected = 0;
	mainMenu();
	cout << "Seleccione un metodo: ";
	cin >> sortSelected;

	ofstream ofs;
	ofstream ofs_time;
	ofs_time.open(sortAlg.getpathdirs("plotfiles") + "exectime_cpp" + sortAlgs[sortSelected] + ".txt",ofstream::out);
	if(ofs_time.is_open()){
		ofs_time << "#NumPrueba" << " " << "TiempoEjecucion" << endl;	
	}else{
		cout << "no se puede abrir archivo de tiempo" << endl;
	}

		
	struct timespec start, end;

	//iterate file by file (21 cases)
	for(int numtest = 0; numtest < indTest.size(); ++numtest){
		//Imprimir el actual caso
		cout<<"Testing file with "<<indTest[numtest] << " cases -> ";
		
		switch(sortSelected){
			case 1:
				//sorting by heapsort
				clock_gettime(CLOCK_MONOTONIC, &start);
				ios_base::sync_with_stdio(false);
				algHeapSort.heapsort(testData[numtest],indTest[numtest]);
				clock_gettime(CLOCK_MONOTONIC, &end);
				break;
			case 2:
				//sorting by quicksort
				clock_gettime(CLOCK_MONOTONIC, &start);
				ios_base::sync_with_stdio(false);
				algQuickSort.quicksort(testData[numtest],0,indTest[numtest]-1);
				clock_gettime(CLOCK_MONOTONIC, &end);
				break;
			default:
				//default will be heapsort
				clock_gettime(CLOCK_MONOTONIC, &start);
				ios_base::sync_with_stdio(false);
				algHeapSort.heapsort(testData[numtest],indTest[numtest]);
				clock_gettime(CLOCK_MONOTONIC, &end);
				break;

		}
		//Saving results of every algorithm
		nameOutputFile = sortAlg.getpathdirs("sortfiles") + sortAlg.getpathdirs("baseFilename") + to_string(indTest[numtest]) +sortAlgs[sortSelected]+".txt";
		ofs.open(nameOutputFile,ofstream::out);
		for(int numSorted=0; numSorted < indTest[numtest]; ++numSorted){
			if(ofs.is_open()){
				ofs << testData[numtest][numSorted] << " ";
			}else{
				cout << "No puede crear archivo de escritura"<<endl;
			}
		}
		ofs.close();		
		//Saving execution time
		double  time_taken;
		time_taken = (end.tv_sec - start.tv_sec) * 1e9;
		time_taken = (time_taken + (end.tv_nsec - start.tv_nsec) * 1e-9);	
		cout << "It last "<<fixed<<time_taken << setprecision(9)<< " seconds"<<endl;
		execTime.push_back(time_taken);

		//times in file
		if(ofs_time.is_open()){
			ofs_time << indTest[numtest] << " " << time_taken << endl;	
		}else{
			cout << "no se puede abrir archivo de tiempo" << endl;
		}

		//Ploteamos con el archivo de tiempo
		sortAlg.writePlotFiles(sortAlgs, sortSelected);	
		
	}
	ofs_time.close();

	//Solicitamos requerimiento de ploteo
	string optionPlot = "";
	string yes = "y";
	string no = "n";
	cout << "Desea Plotear el resultado de tiempos: (y/n)";
	cin >> optionPlot;
	cout << endl;
	if (strcmp(optionPlot.c_str(),yes.c_str())==0 ){
		string tipoAlg = sortAlgs[sortSelected];
	       	string plotfile = "gnuplot PlotFiles/plottime" + tipoAlg + ".dem";	
		//string res = sortAlg.showPlot(gnup);	
		string res = sortAlg.showPlot(plotfile.c_str());	

		cout << res << endl;
	}else if(strcmp(optionPlot.c_str(),no.c_str())==0){
		cout << "nou" << endl;	
	}
	
	return 0;
}
