#include<iostream>
using namespace std;

//Array based Stack
class Stack {
	int* array;
	int size;
	int front;
public:
	Stack(int s)
	{
		size = s;
		array = new int[size];
		for (int i = 0;i < size;i++)
		{
			array[i] = 0;
		}
		front = -1;
	}

	bool IsEmpty()
	{
		return front = -1;
	}
	bool IsFull()
	{
		return front >= size;
	}
	void Push(int val)
	{
		if (IsFull())
			cout << "Your stack is full\n";
		else
		{
			front++;
			array[front] = val;
		}
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			front--;
			array[front];
		}
	}
	int Size()
	{
		if (front == -1)
			return 0;
		else
			return front+1;
	}
	void display()
	{
		if (front == -1)
			cout << "Your stack is empty\n";
		else
		{
			for (int i = 0;i <= front;i++)
			{
				cout << array[i] << "  ";
			}
		}
	}
	~Stack()
	{
		if (size > 0)
			delete[] array;
	}
};

int main()
{
	int SIZE,num,val;
	cout << "Plz enter array size: ";
	cin >> SIZE;
	Stack list(SIZE);
	cout << "How many value you want to push: ";
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		cout << "Push " << i+1 << " value: ";
		cin >> val;
		list.Push(val);
	}
	cout << "How many value you want to pop: ";
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		list.Pop();
	}
	cout << "List size is: " << list.Size();
	list.display();
}

