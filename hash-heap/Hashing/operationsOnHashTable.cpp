#include<iostream>
using namespace std;

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
	friend class LList;
	friend class Hash;
};
class LList
{
	Node* head;
	Node* tail;
public:
	LList()
	{
		head = NULL;
		tail = NULL;
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	void InsertAtHead(int val)
	{
		Node* newnode = new Node(val);
		tail = head = newnode;
	}
	void InsertAfterHead(int val)
	{
		Node* newnode = new Node(val);
		tail->next = newnode;
		tail = newnode;
	}
	friend class Hash;
};
class Hash 
{
	int Size;
	LList *list;
public:
	Hash(int s)
	{
		Size = s;
		list = new LList[Size];
	}
	int Hashfun(int key)
	{
		return key % Size;
	}
	void insert(int key)
	{
		int index = Hashfun(key);
		if (list[index].IsEmpty())
			list[index].InsertAtHead(key);
		else
		{
			list[index].InsertAfterHead(key);
		}
	}
	bool Search(int key)
	{ 
		cout << "\nLet us search " << key << " in hashing table\n";
		for (int i = 0; i < Size; i++)
		{
			if (list[i].head != NULL)
			{
				Node* temp = list[i].head;
				if (key == temp->data)
					return true;
				if (temp->next != NULL)
				{
					while (temp != NULL)
					{
						if (key == temp->data)
							return true;
						temp = temp->next;
					}
				}
			}
		}
		return false;
	}
	void deletion(int key)
	{
		for (int i = 0; i < Size; i++)
		{
			if (list[i].head != NULL)
			{
				Node* temp1 = list[i].head;
				Node* temp2 = list[i].head;
				if (key == temp1->data)
				{
					cout << "\n" << temp1->data << " has been removed\n";
					if (temp1->next != NULL)
					{
						list[i].head = temp1->next;
						break;
					}
					else
					{
						list[i].head = NULL;
						break;
					}
				}
				else
				{
					int count1 = 0;
					int count2 = 0;
					while (temp1->data != key)
					{
						temp1 = temp1->next;
						count1++;
						if (temp1 == NULL)
							break;
					}
					while (count2 < count1 - 1)
					{
						temp2 = temp2->next;
						count2++;
					}
					if (temp1 != NULL)
					{
						temp2->next = temp1->next;
						cout << "\n" << temp1->data << " has been deleted\n";
						temp1 = nullptr;
					}
				}
			}

		}
	}
	void display()
	{
		cout << "\nHashing table is: \n";
		for (int i = 0; i < Size; i++)
		{
			if (list[i].IsEmpty())
				cout << "NULL\n";
			if (!list[i].IsEmpty())
			{
				Node* temp = list[i].head;
				cout << temp->data;
				if (temp->next != NULL)
				{
					temp = temp->next;
					while (temp != NULL)
					{
						cout << " -> " << temp->data;
						temp = temp->next;
					}
				}
				cout << endl;
			}
		}
	}
};
int main()
{
	Hash h(5);

	// Task 1 and 2
	h.insert(56);
	h.insert(80);
	h.insert(50);
	h.insert(78);
	h.insert(55);
	h.insert(66);
	h.insert(43);
	h.display();

	// Task 4
	if (h.Search(40))
		cout << "\nElement is found\n";
	else
		cout << "\nElement is not found\n";

	// Task 3
	h.deletion(43);
	h.display();
	h.deletion(78);
	h.display();
}