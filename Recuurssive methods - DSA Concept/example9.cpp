#include<iostream>
using namespace std;

int linearFib(int a, int b, int n)
{
	if (n <= 2)
		return b;
	else
		return linearFib(b, a + b, n - 1);
}
int binaryFib(int n)
{
	if (n <= 1)
		return n;
	else
		return binaryFib(n - 1) + binaryFib(n - 2);
}
int main()
{
	cout << "\nLinear fibonaci series is: ";
	for (int i = 1; i <= 10; i++)
	{
		cout<<linearFib(1,1, i)<<"  ";
	}
	cout << endl;
	cout << "\nBinary fibonaci series is: ";
	for (int i = 1; i <= 10; i++)
	{
		cout << binaryFib(i) << "  ";
	}
}