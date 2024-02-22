#include<iostream>
#include<stack>
using namespace std;

// Number of nodes in linked list and display reversed linked list

class Node {
	Node* next;
	int data;
public:
	Node(int d = 0)
	{
		next = NULL;
		data = d;
	}
	friend class linkedlist;
};
class linkedlist {
	Node* head;
	Node* tail;
	int countNodes(Node* head) const
	{
		if (head != nullptr)
			return 1 + countNodes(head->next);
		else
			return 0;
	}
	void showReverse(Node* head) const
	{
		if (head != nullptr)
		{
			showReverse(head->next);
			cout << head->data << "  ";
		}
	}
public:
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	bool IsEmpty()
	{
		return head = NULL;
	}
	void Insertnode(int val)
	{
		Node* newNode = new Node(val);
		if (IsEmpty())
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	int numNodes() const
	{
		return countNodes(head);
	}
	void displayBackwards() const
	{
		showReverse(head);
	}
	void display()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
};
int main()
{
	int num = 0;
	linkedlist list;
	cout << "Enter number of nodes you want to enter: ";
	cin >> num;
	cout << "Number of nodes are:  ";
	for (int i = 1; i <= num; i++)
	{
		list.Insertnode(i * i);
	}
	list.display();
	cout << list.numNodes();
}