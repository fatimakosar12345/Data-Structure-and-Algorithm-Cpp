#include<iostream>
using namespace std;
#define SIZE 500

// Binary Tree of array

class Node
{
	Node* leftchild;
	Node* rightchild;
	int data;
public:
	Node(int d = 0)
	{
		leftchild = NULL;
		rightchild = NULL;
		data = d;
	}
	friend class BinaryTree;
};
class BinaryTree
{
public:
	int treenodes[SIZE];
	int l, length = 0;
	BinaryTree()
	{
		for (int i = 0; i < SIZE; i++)
		{
			treenodes[i] = -1;
		}
	}
	int leftchild(int nodeindex)             //returns the index of the left child
	{
		int rv = (2 * nodeindex) + 1;
		return (rv >= SIZE || treenodes[rv] == -1) ? -1 : rv;
	}
	int rightchild(int nodeindex)            //returns the index of the right child
	{
		int rv = (2 * nodeindex) + 2;
		return(rv >= SIZE || treenodes[rv] == -1) ? -1 : rv;
	}
	bool Isleaf(int nodeindex)
	{
		return leftchild(nodeindex) == -1 && rightchild(nodeindex) == -1;
	}
	int parent(int nodeindex)
	{
		int rv = (nodeindex - 1) / 2;
		return (rv >= SIZE || treenodes[rv] == -1) ? -1 : rv;
	}
	bool rootnode(int value)
	{
		treenodes[0] = value;
		cout << "\nRoot node is " << treenodes[0] << " at index " << 0;
		length++;
		return true;
	}
	bool addleftchild(int value, int parent)
	{
		int index = (2 * parent) + 1;
		if (index < SIZE)
		{
			treenodes[index] = value;
			cout << "\nSetted left child " << treenodes[index] << " at index " << index;
			length++;
			return true;
		}
		else
		{
			cout << "\ncan't set left child";
			return false;
		}
	}
	bool addrightchild(int value, int parent)
	{
		int index = (2 * parent) + 2;

		if (index < SIZE)
		{
			treenodes[index] = value;
			l = index;
			cout << "\nSetted right child " << treenodes[index] << " at index " << index;
			length++;
			return true;
		}
		else
		{
			cout << "\ncan't set right child";
			return false;
		}
	}
	void display()
	{
		for (int i = 0; i <= l; i++)
		{
			cout << endl << treenodes[i] << "  ";
		}
		cout << endl;
	}
};
int main()
{
	BinaryTree T;
	T.rootnode(89);
	T.addleftchild(78, 0);
	T.addrightchild(67, 0);
	T.addleftchild(70, 1);
	T.addrightchild(60, 1);
	T.addleftchild(80, 2);
	T.addrightchild(56, 2);
	T.display();
}