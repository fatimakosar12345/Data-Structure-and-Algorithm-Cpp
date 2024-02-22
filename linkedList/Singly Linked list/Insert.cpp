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
	void InsertAtTail(int val)
	{
		Node* Newnode = new Node(val);
		
		if (IsEmpty())
		{
			head = tail = Newnode;
			length++;
		}
		else if (temp == NULL)
		{
			tail->next = Newnode;
			tail = Newnode;
			length++;
		}
		else
		{
			temp = temp->next;
			InsertAtTail(val);
			delete Newnode;
		}
	}
	void display()
	{
		Node* temp = head;
		if (IsEmpty())
			cout << "Your linkedlist is empty\n";
		else
		{
			while (temp != NULL)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
		}
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
	list.InsertAtTail(76);
	list.InsertAtTail(56);
	list.display();
}