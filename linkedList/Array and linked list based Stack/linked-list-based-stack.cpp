#include<iostream>
using namespace std;

//linked list based Stack
class Node
{
	int data;
	Node* next;
public:
	Node(int val)
	{
		data = val;
		next = NULL;
	}
	friend class Stack;
};
class Stack
{
	Node* head;
	Node* tail;
	int length = 0;
public:
	Stack()
	{
		head = NULL;
		tail = NULL;
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	void Push(int val)
	{
		Node* newNode = new Node(val);
		if (head == NULL)
		{
			head = tail = newNode;
			length++;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
			length++;
		}
	}
	void Pop()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		length--;
	}
	int Length()
	{
		return length;
	}
	int top()
	{
		return head->data;
	}
	void display()
	{
		Node* temp = head;
		if (IsEmpty())
			cout << "Your Stack is empty\n";
		else
		{
			while (temp != NULL)
			{
				cout << temp->data << "   \n";
				temp = temp->next;
			}
		}
	}
};

int main()
{
	Stack list;
	list.Push(89);
	list.Push(78);
	list.Push(49);
	list.Push(28);
	list.display();
	list.Pop();
	list.Pop();
	list.display();
}