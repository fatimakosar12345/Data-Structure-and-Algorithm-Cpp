#include<iostream>
#include<stack>
using namespace std;

//To count number of characters

int numChars(char search, string str, int subscript)
{
	if (subscript >= str.length())
	{
		return 0;
	}
	else if (str[subscript] == search)
	{
		return 1 + numChars(search, str, subscript + 1);
	}
	else
	{
		return numChars(search, str, subscript + 1);
	}
}
int main()
{
	string str = "abcdddeff";

	//Display the number of times the letter 'd' appears in string
	cout << "The letter d appears " << numChars('d', str, 0) << " times.\n";
}