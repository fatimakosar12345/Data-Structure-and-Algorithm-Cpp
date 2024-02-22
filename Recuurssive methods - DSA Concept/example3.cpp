#include<iostream>
#include<stack>
using namespace std;

//Fibonacci series

int fib(int);

int main()
{
	cout << "The first 10 Fibonacci numbers are:\n";
	for (int x = 0; x < 10; x++)
	{
		cout << fib(x) << "  ";
	}
	cout << endl;
}

int fib(int n)
{
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}