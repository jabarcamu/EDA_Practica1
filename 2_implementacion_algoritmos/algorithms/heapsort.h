#ifndef heapsort_h
#define heapsort_h

class Heapsort{
	private:
		int num;
	public:
		Heapsort();
		//Heapsort(int n);
		//int getNum();
		void heapify(int arr[], int n, int i);
		void heapsort(int arr[], int n);
		void printArray(int arr[], int n);

};

#endif
