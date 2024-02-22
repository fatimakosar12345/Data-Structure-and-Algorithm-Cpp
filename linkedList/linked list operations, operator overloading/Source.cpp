#include<iostream>
using namespace std;

template <class E>
class linkedlist;

template <class E>
class Node 
{
	Node<E>* next;
	E data;
public:
	Node(E d = 0)
	{
		data = d;
		next = NULL;
	}
	friend class linkedlist<E>;
};

template <class E>
class linkedlistIterator
{
	Node<E>* current;
public:
	linkedlistIterator()
	{
		current = NULL;
	}
	linkedlistIterator(Node<E>* ptr)
	{
		current = ptr;
	}
	E operator*()
	{
		return current->data;
	}
	linkedlistIterator<E> operator++()
	{
		current = current->next;
		return *this;
	}
	bool operator==(const linkedlistIterator<E>& right)
	{
		return current == right.current;
	}
	bool operator!=(const linkedlistIterator<E>& right)
	{
		return current != right.current;
	}
};

template <class E>
class linkedlist
{
public:
	Node<E>* first = NULL;
	Node<E>* last;
	int length;
	int count = 0;
public:
	linkedlist()
	{
		first = NULL;
		last = NULL;
		length = 0;
	}
	bool IsEmpty()
	{
		return first == NULL;
	}
	void InsertNode(E val)
	{
		Node<E>* newnode = new Node<E>(val);
		if (IsEmpty())
		{
			first = last = newnode;
			length++;
		}
		else
		{
			last->next = newnode;
			last = newnode;
			length++;
		}
	}
	void delnode(E val)
	{
		Node<E>* temp1 = first;
		Node<E>* temp2 = first;
		int count1 = 0;
		int count2 = 0;
		while (temp1->data != val)
		{
			temp1 = temp1->next;
			count1++;
		}
		while (count2 < count1-1)
		{
			temp2 = temp2->next;
			count2++;
		}
		temp2->next = temp1->next;
		delete temp1;
	}
	void display()
	{
		Node<E>* temp = first;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	/*void letfind()
	{
		Node<E>* temp = first;
		linkedlistIterator<int> Ite1(first);
		linkedlistIterator<int> Ite2(temp);
		if (Ite1 == Ite2)
			cout << "Matched\n";
		else
			cout << "Not matched\n";
		cout << Ite1++;
	}*/

	void destroylist()
	{
		Node<E>* temp;
		while (first != NULL)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
		last = NULL;
		count = 0;
	}

	void sorting()
	{
		int temp;
		bool swapped = true;
		while (swapped)
		{
			Node<E>* Previous = first;
			Node<E>* current = Previous->next;
			swapped = false;
			while (current != NULL)
			{
				if (Previous->data > current->data)
				{
					temp = current->data;
					current->data = Previous->data;
					Previous->data = temp;
					swapped = true;
				}
				Previous = Previous->next;
				current = current->next;
			}
		}
	}

	const linkedlist<E>& operator=(const linkedlist<E>& otherlist)
	{
		if (this != &otherlist)
		{
			Node<E>* newNode;
			Node<E>* current;
			
			if (first != NULL)
				destroylist();

			if (otherlist.first == NULL)
			{
				first = NULL;
				last = NULL;
				count = 0;
			}
			else
			{
				current = otherlist.first;
				count = otherlist.count;

				first = new Node<E>;
				first->data = current->data;
				first->next = NULL;

				last = first;
				current = current->next;

				while (current != NULL)
				{
					newNode = new Node<E>;
					newNode->data = current->data;
					newNode->next = NULL;

					last->next = newNode;
					last=newNode;

					current = current->next;
				}
			}
		}
		return *this;
	}
};

int main()
{
	linkedlist<int> list;
	linkedlist<int> Copylist;
	list.InsertNode(56);
	list.InsertNode(45);
	list.InsertNode(40);
	list.InsertNode(23);
	list.InsertNode(70);
	list.display();
	list.delnode(23);
	list.sorting();
	list.display();
//	list.letfind();
	Copylist = list;
	Copylist.display();
}