#include<iostream>
#include<stack>
using namespace std;

void Array(int arr[],int size)
{
		if (size > 0)
		{
			cout << arr[size-1] << "  ";
			Array(arr, size - 1);
			cout << endl;
			cout << arr[size - 1] << "  ";
		}
		//cout << arr[size - 1 ] << "  ";
}

int main()
{
	const int size = 4;
	int arr[size];
	cout << "Enter array elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	Array(arr, size);
}
