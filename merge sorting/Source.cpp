#include<iostream>
using namespace std;

class MS {
	int size;
	int* array1;
	int* array2;
public:
	MS(int s)
	{
		size = s;
		array1 = new int[size+1];
		array2 = new int[size + 1];
		cout << "Enter array elements:  ";
		for (int i = 0; i <= size; i++)
		{
			cin >> array1[i];
		}
	}
	void merge(int lb, int mid, int ub)
	{
		for (int i = 0; i <= size; i++)
		{
			array2[i] = 0;
		}
		int i = lb;
		int j = mid + 1;
		int k = lb;
		cout << ub;
		while (i <= mid && j <= ub)
		{
			if (array1[i] <= array1[j])
			{
				array2[k] = array1[i];
				i++;
			}
			else
			{
				array2[k] = array1[j];
				j++;
			}
			k++;
		}
		if (i > mid)
		{
			while (j <= ub)
			{
				array2[k] = array1[j];
				j++;
				k++;
			}
		}
		else
		{
			while (i <= mid)
			{
				array2[k] = array1[i];
				i++;
				k++;
			}
		}
		for (k = lb; k <= ub; k++)
		{
			array1[k] = array2[k];
		}
	}

	void mergeSort(int lb, int ub)
	{
		if (lb < ub)
		{
			int mid = (lb + ub) / 2;
			mergeSort(lb, mid);
			mergeSort(mid + 1, ub);
			merge(lb, mid, ub);
		}
	}

	void display()
	{
		cout << "\nArray elements are: \n";
		for (int i = 0; i <= size; i++)
		{
			cout << array1[i] << "  ";
		}
		cout<<endl;
	}
};
int main()
{
	const int size = 3;
	
	MS obj(size);
	obj.display();
	obj.mergeSort(0, size);
	obj.display();
}

