#include<iostream>
#include<stack>
using namespace std;

void mystery(stack<int>& s, stack<int>& t);

int main()
{
	int list[] = { 5,10,15,20,25 };

	stack<int> s1;
	stack<int> s2;

	for (int i = 0; i < 5; i++)
	{
		s1.push(list[i]);
	}

	mystery(s1, s2);

	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
}
void mystery(stack<int>& s, stack<int>& t)
{
	while (!s.empty())
	{
		t.push(2 * s.top());
		s.pop();
	}
}