#include "algorithms/heapsort.h"
#include "SortAlg.h"


using namespace std;
int main(){
    	SortAlg sortAlg;
	sortAlg.assignDefaultValues();
	sortAlg.loadTestData();

	int *res = sortAlg.getArray();
	
	//Aplicar Heapsort y ver el array afectado
	//Heapsort algHeapSort;
	//algHeapSort.heapsort(res,500);
	
	//sortAlg.printArray(500);
	sortAlg.genDicNumeroItems();
    	return 0;
}
