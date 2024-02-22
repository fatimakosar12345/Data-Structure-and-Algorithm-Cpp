#include<iostream>
using namespace std;

// array based Queue

class Queue
{
	int SIZE;
	int* array;
	int front;
	int rear;
public:
	Queue(int s)
	{
		SIZE = s;
		array = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			array[i] = 0;
		}
		front = -1;
		rear = -1;
	}
	bool IsEmpty()
	{
		return front == -1;
	}
	bool IsFull()
	{
		return rear == SIZE - 1;
	}
	void Enqueue(int val)
	{
		if (IsFull())
			cout << "You can not Enqueue\n";
		else
		{
			if (front == -1)
			{
				front = 0;
				array[front] = val;
			}
			rear++;
			array[rear] = val;
		}
	}
	void Dequeue()
	{
		if (IsEmpty())
			cout << "You can not dequeue\n";
		else
		{
			front++;
			array[front];
		}
	}
	void display()
	{
		if (IsEmpty())
			cout << "Your Queue is Empty\n";
		else
		{
			for (int i = front; i < rear + 1; i++)
			{
				cout << array[i] << "  ";
			}
		}
		cout << endl;
	}
};
void menu()
{
	int size,num,ele;
	cout << "Enter array size for QUEUE: ";
	cin >> size;
	Queue Q(size);
	int choice;
	char option;
	do
	{
		cout << "1-> To ENQUEUE data\n";
		cout << "2-> To DEQUEUE data\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter number of elements you want to ENQUEUE: ";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				cout << "Enter " << i + 1 << " element: ";
				cin >> ele;
				Q.Enqueue(ele);
			}
			cout << "Your Queue is: \n";
			Q.display();
		}
		else if (choice == 2)
		{
			cout << "Enter number of elements you want to DEQUEUE: ";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				Q.Dequeue();
			}
			cout << "Your Queue is: \n";
			Q.display();
		}
		else
		{
			cout << "you have entered invalid choice\n";
		}
		cout << "Do you want to continue(Y or y for yes N or n for no):   ";
		cin >> option;
	} while (option == 'Y' || option == 'y');
}
int main()
{
	menu();
}

