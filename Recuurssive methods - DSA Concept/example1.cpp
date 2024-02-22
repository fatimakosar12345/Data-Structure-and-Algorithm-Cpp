#include<iostream>
#include<stack>
using namespace std;

void selfcall(int num)
{
	cout << "hello i am outside the function before call\n";
	if (num > 0)
	{
		cout << "i am inside the if condition 1 " << num << "\n";
		selfcall(num - 1);
		cout << "i am inside the if condition 2 " << num << "\n";
	}
	cout << "hello i am outside the function after call " << num << "\n";
}
int main()
{
	selfcall(6);
}