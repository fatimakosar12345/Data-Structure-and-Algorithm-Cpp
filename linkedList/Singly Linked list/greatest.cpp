#include<iostream>
using namespace std;

class Node
{
	Node* next;
	int data;
public:
	Node(int d = 0)
	{
		next = NULL;
		data = d;
	}
	friend class Linkedlist;
};

class Linkedlist
{
	Node* head;
	Node* tail;
	Node* temp;
	int length;
	int num;
	int greatest = 0;
public:
	Linkedlist()
	{
		head = temp = tail = NULL;
		length = 0;
		num = 1;
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	void Insertnode(int val)
	{
		Node* Newnode = new Node(val);
		if (IsEmpty())
		{
			head = temp = tail = Newnode;
			length++;
		}
		else
		{
			tail->next = Newnode;
			tail = Newnode;
			length++;
		}
	}
	int Greatest()
	{

		if (temp->data < temp->next->data)
		{
			greatest = temp->next->data;
			temp = temp->next;
			Greatest();
			return greatest;
		}
		else if (temp->next == NULL)
			return 0;
	}
};
int main()
{
	Linkedlist list;
	list.Insertnode(67);
	list.Insertnode(87);
	list.Insertnode(586);
	list.Insertnode(600);
	list.Insertnode(880);
	list.Insertnode(50);
	cout << "Greatest value in linked list is:  " << list.Greatest();
}
