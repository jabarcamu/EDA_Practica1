#ifndef quicksort_h
#define quicksort_h

class Quicksort{
	public:
		Quicksort();
		int partition(int arr[], int low, int high);
		void quicksort(int arr[], int low, int high);
		void printArray(int arr[], int size);
};
#endif
