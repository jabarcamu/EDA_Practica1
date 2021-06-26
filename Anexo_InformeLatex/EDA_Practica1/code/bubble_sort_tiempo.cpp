
#include <chrono>

	auto t1 = std::chrono::high_resolution_clock::now();
	//... (Bubble Sort)
	auto t2 = std::chrono::high_resolution_clock::now();
	
	//calcular, convertir e imprimir tiempo
	std::chrono::duration<double> elapsed = t2 - t1;
	float miliseg = (float)(elapsed.count());
	cout<<archivos[indx]<<","<<setprecision(4)<<miliseg<<endl;
    