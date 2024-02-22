#include<iostream>
using namespace std;

int Partition(int array[], int lb, int ub)
{
	int pivot = array[lb];
	int start = lb;
	int end = ub;
	while (start < end)
	{
		while (array[start] <= pivot)
		{
			start++;
		}
		while (array[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			swap(array[start], array[end]);
		}
	}
	swap(array[lb], array[end]);
	return end;
}

void QuickSort(int array[], int lb, int ub)
{
	if (lb < ub)
	{
		int loc = Partition(array, lb, ub);
		QuickSort(array, lb, loc - 1);
		QuickSort(array, loc + 1, ub);
	}
}

int main()
{
	int array[4] = { 5,3,8,2 };
	QuickSort(array, 0, 3);
	for (int i = 0; i < 4; i++)
	{
		cout << array[i] << "  ";
	}
}