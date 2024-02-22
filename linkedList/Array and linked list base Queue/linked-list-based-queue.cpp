#include<iostream>
using namespace std;

// linked list based Queue

class Node
{
	Node* next;
	int data;
public:
	Node(int val = 0)
	{
		next = NULL;
		data = val;
	}
	friend class Queue;
};
class Queue 
{
	Node* front;
	Node* rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	bool IsEmpty()
	{
		return front == NULL;
	}
	void Enqueue(int val)
	{
		Node* newnode = new Node(val);
		if (IsEmpty())
			front = rear = newnode;
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}
	void Dequeue()
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	void display()
	{
		Node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
};
void menu()
{
	int num, ele;
	Queue Q;
	int choice;
	char option;
	do
	{
		cout << "Here are QUEUE choices\n";
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
		cout << "\nDo you want to continue(Y or y for yes N for no):   ";
		cin >> option;
	} while (option == 'Y' || option == 'y');
}
int main()
{
	menu();
}