#include<iostream>
using namespace std;
#define SIZE 500

// Binary Tree by recurssion method

class Node 
{
	Node* left;
	Node* right;
	int data;
public:
	Node(int d = 0)
	{
		left = NULL;
		right = NULL;
		data = d;
	}
	friend class Tree;
};
class Tree 
{
	Node* root;
public:
	Tree() 
	{
		root = NULL;
	}
	Node* create()
	{
		int x;
		Node* newnode = new Node;
		cout << "\nEnter data: ";
		cin >> x;
		if (x == -1)
			return 0;
		newnode->data = x;
		cout << "\nEnter left child of " << x << " : ";
		
		newnode->left = create();
		cout << "\nEnter right child of " << x << " : ";
		
		newnode->right = create();
	}
	void call() 
	{
		root = create();
	}
};
int main()
{
	Tree T;
	T.call();
}
