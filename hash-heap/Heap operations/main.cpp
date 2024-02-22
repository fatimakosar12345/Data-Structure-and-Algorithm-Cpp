#include<iostream>
using namespace std;

//Max Heap Tree
void max_heapify(int[], int, int);
void build_maxheap(int[], int);

//Min Heap Tree
void min_heapify(int[], int, int);
void build_minheap(int[], int);

//Diaplay
void display(int[], int);

//Heap Sort
void heap_sort(int[], int);


//DRIVER CODE
int main() {
	const int SIZE = 8;

	//0 index of array is initialized with -1
	//becuase we are using 1-based indexing to store binary tree
	int num[SIZE] = { -1,15,5,20,1,17,10,30 };

	cout << "\nHEAP SORTING\n";
	heap_sort(num, SIZE - 1);
}


//Defining Functions for Max Heap Tree
void max_heapify(int arr[], int i, int size) {
	int left = 2 * i;
	int right = 2 * i + 1;
	int largest = i;

	if (left <= size && arr[left] > arr[i])
		largest = left;
	if (right <= size && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		max_heapify(arr, largest, size);
	}
}
void build_maxheap(int arr[], int size) {
	for (int i = size / 2; i >= 1; i--) {
		max_heapify(arr, i, size);
	}
}


//Defining Functions For Min Heap Tree
void min_heapify(int arr[], int i, int size) {
	int left = 2 * i;
	int right = 2 * i + 1;
	int smallest = i;

	if (left <= size && arr[left] < arr[i])
		smallest = left;
	if (right <= size && arr[right] < arr[smallest])
		smallest = right;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		min_heapify(arr, smallest, size);
	}
}
void build_minheap(int arr[], int size) {
	for (int i = size / 2; i >= 1; i--) {
		min_heapify(arr, i, size);
	}
}


//Display
void display(int arr[], int size) {
	for (int count = 1; count <= size; count++) {
		cout << arr[count] << "\t";
	}
	cout << endl << endl;
}


//Heap Sort
void heap_sort(int arr[], int size) {
	//Heap Sort due to max heap tree
	build_maxheap(arr, size);
	int N1 = size;
	for (int i = size; i >= 1; i--) {
		swap(arr[1], arr[i]);
		N1 = N1 - 1;
		max_heapify(arr, 1, N1);
	}
	cout << "Heap Sort due to max heap tree\n";
	display(arr, size);


	//Heap Sort due to min heap tree
	build_minheap(arr, size);
	int N2 = size;
	for (int i = size; i >= 1; i--) {
		swap(arr[1], arr[i]);
		N2 = N2 - 1;
		min_heapify(arr, 1, N2);
	}
	cout << "Heap Sort due to min heap tree\n";
	display(arr, size);
}