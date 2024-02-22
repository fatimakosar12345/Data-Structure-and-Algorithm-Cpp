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
	void Search(int val)
	{
		if (temp == NULL)
			cout << "Element is not found\n";
		else if (temp->data == val)
			cout << "Element is found at " << num << " place of linked list\n";
		else
		{
			num++;
			temp = temp->next;
			Search(val);
		}
	}
};
int main()
{
	Linkedlist list;
	list.Insertnode(67);
	list.Insertnode(87);
	list.Insertnode(56);
	list.Insertnode(60);
	list.Insertnode(80);
	list.Insertnode(50);
	list.Search(80);
}