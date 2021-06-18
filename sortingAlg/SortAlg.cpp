#include "SortAlg.h"
SortAlg::SortAlg(){}

void SortAlg::assignDefaultValues(){
	memset(arrayint,0,500);
}


void SortAlg::loadTestData()
{
    	string line;
    	std::ifstream ifs;
    	ifs.open("generatedTestData/example_500.txt", std::ifstream::in);
    	int idx = 0;
    	if(ifs.is_open()){
        	while(getline(ifs, line))
        	{
            	//cout << line << "\n";
            	arrayint[idx] = stoi(line);
            	idx++;
        	}
        	ifs.close();
	}
	else cout << "No se pudo abrir el archivo"<<endl;
}

int* SortAlg::getArray(){
	return arrayint;
}

void SortAlg::printArray(int n){
  for (int i=0; i<n; ++i)
      cout << arrayint[i] << " ";
  cout << "\n";    
}

//template<typename Map>
void SortAlg::genDicNumeroItems(){
	
	/*
	map<int,string> map1 = {{1,"Manzana",},
				{2,"Pera",}};
	cout << "[";
	for(auto &item : map1){
		cout << item.first << ":" << item.second << " ";
	}
	cout << "]\n";
	*/
		
}

