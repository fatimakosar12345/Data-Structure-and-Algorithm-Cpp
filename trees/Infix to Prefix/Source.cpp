#include<iostream>
using namespace std;

class Node {
public:
	Node* next;
	char data;
public:
	Node(char c)
	{
		next = NULL;
		data = c;
	}
};
class Stack {
	Node* head;
	int length = 0;
public:
	Stack()
	{
		head = NULL;
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	void Push(char c)
	{
		Node* newnode = new Node(c);
		if (IsEmpty())
		{
			head = newnode;
			length++;
		}
		else 
		{
			newnode->next = head;
			head = newnode;
			length++;
		}
	}
	Node* Pop()
	{
		Node* temp = head;
		head = head->next;
		return temp;
	}
	char top()
	{
		return head->data;
	}
};
int inputprec(char input)
{
	int num = 0;
	if (input == '+' || input == '-')
		num = 1;
	else if (input == '*' || input == '/' || input == '%')
		num = 2;
	else if (input == '^')
		num = 7;
	return num;
}
int outputprec(char input)
{
	int num = 0;
	if (input == '+' || input == '-')
		num = 1;
	else if (input == '*' || input == '/' || input == '%')
		num = 2;
	else if (input == '^')
		num = 3;
	return num;
}
void evaluatePreFix(string str) {
	Stack s;
	Node* p = nullptr;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
			p = s.Pop();
			int num1 = p->data;
			p = s.Pop();
			int num2 = p->data;
			switch (str[i]) {
			case '+':
				s.Push(num1 + num2);
				break;
			case '-':
				s.Push(num1 - num2);
				break;
			case '/':
				s.Push(num1 / num2);
				break;
			case '*':
				s.Push(num1 * num2);
				break;
			}
		}
		else {
			s.Push(int(str[i] - '0'));
		}
	}
	p = s.Pop();
	cout << p->data;
	cout << endl;
	delete p;
	p = nullptr;
}
string InfixToPrefix(string infix)
{
	string temp;
	string add;
	Stack s;
	Node* n = nullptr;
	for (int i = infix.length() - 1;i >= 0;i--)
	{
		temp += infix[i];
	}
	infix = temp;
	for (int i = 0; i < infix.length(); i++)
	{
		if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
		{
			add += infix[i];
		}
		else if (s.IsEmpty())
			s.Push(infix[i]);
		else if (infix[i]==')'||s.top() == ')')
		{
			s.Push(infix[i]);
		}
		else if (infix[i] == '(')
		{
			while (s.top() != ')')
			{
				n = s.Pop();
				add += n->data;
			}
			s.Pop();
		}
		else
		{
			while (!s.IsEmpty() && (inputprec(s.top()) > outputprec(infix[i])))
			{
				n = s.Pop();
				add += n->data;
			}
			s.Push(infix[i]);
		}
	}
	while (!s.IsEmpty())
	{
		n = s.Pop();
		add += n->data;
	}
	temp = "";
	evaluatePreFix(add);
	for (int i = add.length() - 1;i >= 0;i--)
	{
		temp += add[i];
	}
	add = temp;
	return add;
	delete n;
	n = nullptr;
}
int main()
{
	string str = "(2+7)-(8*7)";
	cout<<InfixToPrefix(str);
}

