#include "SortAlg.h"


SortAlg::SortAlg(){

	//Inicializando rutas y directorios	
	mapPathDirs.insert(make_pair("sortfiles","SortFiles/"));
	mapPathDirs.insert(make_pair("plotfiles","PlotFiles/"));
	mapPathDirs.insert(make_pair("testfiles","generatedTestData/"));
	mapPathDirs.insert(make_pair("baseFilename","example_"));
	
	//creando los directorios principales
	if((mkdir(mapPathDirs["sortfiles"].c_str(),0777)==-1) and 
		(mkdir(mapPathDirs["plotfiles"].c_str(),0777)==-1) and
		(mkdir(mapPathDirs["testfiles"].c_str(),0777)==-1)){
		cerr << "Error creando directorio "<< mapPathDirs["sortfiles"] << strerror(errno) << endl;
	}else
		cout << "Directorio SortFiles creado..." << endl;
}

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
	//retorna cero si no pudo leerse ele vecIndTest
	return 0;
}

vector<int> SortAlg::getIndTest(){
	return vecIndTest;
}
string SortAlg::getpathdirs(string keyPathDir){
	return mapPathDirs[keyPathDir];
}

void SortAlg::writePlotFiles(map<int,string> &sortAlgs, int selectedSort){
	ofstream ofs;
	//heapsort
	ofs.open(mapPathDirs["plotfiles"] + "plottime"+ sortAlgs[selectedSort]+".dem", ofstream::out);
	//formato de salida en imagenes svg
	ofs << "set terminal svg" << endl;
	ofs << "set output  \""+mapPathDirs["plotfiles"]+"exectime"+sortAlgs[selectedSort]+"_cpp.svg\"" << endl;
	//propiedades generales
	ofs << "set style data linespoints" << endl;
	ofs << "set title \"Execution Time "+ sortAlgs[selectedSort] +" in C++\"" << endl;
	ofs << "set offset 0,0,0.5,0.5" << endl;
	ofs << "set autoscale fix" << endl;
	ofs << "set key left Left" << endl;
	ofs << "plot [0:100000][0:0.05] \""+mapPathDirs["plotfiles"]+"exectime_cpp"+sortAlgs[selectedSort]+".txt\" ";
	ofs << "using 1:2 title \" Time\" with linespoints ps 2 pt 4" << endl;
	ofs.close();

}

string SortAlg::showPlot(char const* cmd){
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if(!pipe){
		throw std::runtime_error("popen() failed");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr){
		result += buffer.data();
	}
	result += " Ploteo Finalizado";
	return result;
}
