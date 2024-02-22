#include<iostream>
#include<stack>
using namespace std;

//Finding GCD (Greatest Common Divisor)

int gcd(int x, int y)
{
	if (x % y == 0)
		return y;             //Base case
	else
		return gcd(y, x % y); //Recursive case
}

int main()
{
	int num1, num2;

	//Get two numbers
	cout << "Enter two integers:  ";
	cin >> num1 >> num2;

	//Display the GCD of the numbers
	cout << "The greatest common divisor of " << num1;
	cout << " and " << num2 << " is ";
	cout << gcd(num1, num2) << endl;

	return 0;
}
