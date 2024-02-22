#include<iostream>
using namespace std;

class Node
{
	Node* next;
	int id;
	int cgpa;
	string name;
public:
	Node(int Id = 0, string Name = "", int Cgpa = 0)
	{
		next = NULL;
		id = Id;
		name = Name;
		cgpa = Cgpa;
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
	void InsertAtHead(string name, int id, int cgpa)
	{
		Node* newnode = new Node(id, name, cgpa);
		tail = head = newnode;
	}
	void InsertAfterHead(string name, int id, int cgpa)
	{
		Node* newnode = new Node(id, name, cgpa);
		tail->next = newnode;
		tail = newnode;
	}
	friend class Hash;
};
class Hash
{
	int Size;
	LList* list;
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
	void insert(int key, string name, int id, int cgpa)
	{
		int index = Hashfun(key);
		if (list[index].IsEmpty())
			list[index].InsertAtHead(name, id, cgpa);
		else
		{
			list[index].InsertAfterHead(name, id, cgpa);
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
				if (key == temp->name[i])
					return true;
				if (temp->next != NULL)
				{
					while (temp != NULL)
					{
						if (key == temp->name[i])
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
				if (key == temp1->name[i])
				{
					cout << "\n" << temp1->name[i] << " has been removed\n";
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
					while (temp1->name[i] != key)
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
						cout << "\n" << temp1->name[i] << " has been deleted\n";
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
				cout << temp->name << " ";
				cout << temp->id << " ";
				cout << temp->cgpa << " ";
				if (temp->next != NULL)
				{
					temp = temp->next;
					while (temp != NULL)
					{
						cout << " -> " << temp->name << " " << temp->id << " " << temp->cgpa;
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
	Hash h(3);

	h.insert(int('s'), "sara", 4, 3.6);
	h.insert(int('f'), "fatima", 5, 3.8);
	h.insert(int('a'), "ali", 7, 3.2);
	h.insert(int('t'), "talha", 3, 3.9);

	h.display();
	if (h.Search(int('a')))
		cout << "Data is present in hash table" << endl;
	else
		cout << "Data is not present in hash table" << endl;

}