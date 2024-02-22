#include<iostream>
using namespace std;

class Node 
{
	Node* next;
	Node* prev;
	int data;
public:
	Node(int d = 0, Node* n = nullptr, Node* p = nullptr)
	{
		next = n;
		prev = p;
		data = d;
	}
	friend class doublylinkedlist;
};
class doublylinkedlist 
{
	Node* head;
	Node* tail;
	int length = 0;
public:
	doublylinkedlist()
	{
		head = new Node();
		tail = new Node();
		head->prev = nullptr;
		tail->next = nullptr;
		head->next = tail;
		tail->prev = head;
	}
	bool IsEmpty()
	{
		return head->next == tail;
	}
	void InsertAtStart(int val)
	{
		Node* newnode = new Node(val);
		if (IsEmpty())
		{
			newnode->prev = head;
			newnode->next = tail;
			head->next = newnode;
			tail->prev = newnode;
			length++;
		}
		else
		{
			newnode->prev = head;
			newnode->next = head->next;
			head->next = newnode;
			length++;
		}
	}
	void InsertAtLast(int val)
	{
		Node* newnode = new Node(val);
		if (IsEmpty())
		{
			newnode->prev = head;
			newnode->next = tail;
			head->next = newnode;
			tail->prev = newnode;
			length++;
		}
		else
		{
			newnode->next = tail;
			newnode->prev = tail->prev;
			tail->prev = newnode;
			length++;
		}
	}
	void sorting()
	{
		bool swapped = true;
		
		int temp = 0;
		while (swapped)
		{
			Node* previous = head;
			Node* curr = previous->next;
			swapped = false;
			while (curr != NULL)
			{
				if (previous->data > curr->data)
				{
					temp = curr->data;
					curr->data = previous->data;
					previous->data = temp;
					swapped = true;
				}
				previous = previous->next;
				curr = curr->next;
			}
		}
	}
	void display()
	{
		Node* temp = head->next;
		if (IsEmpty())
			cout << "\nyour list is empty\n";
		else
		{
			while (temp->next != nullptr)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};
int main()
{
	doublylinkedlist list;
	//list.InsertAtLast(76);
	list.InsertAtStart(43);
	list.InsertAtStart(59);
	list.InsertAtStart(65);
	list.InsertAtStart(45);
	list.display();
	list.sorting();
	list.display();
}