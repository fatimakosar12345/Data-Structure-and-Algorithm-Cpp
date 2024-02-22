#include<iostream>
using namespace std;

class BSTNode
{
public:
	BSTNode();
	BSTNode(int value);
	void setLeft(BSTNode* left);
	void setRight(BSTNode* right);
	void setParent(BSTNode* parent);
	BSTNode* getLeft();
	BSTNode* getRight();
	BSTNode* getParent();
	int getInfo();
	void setInfo(int info);
private:
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
	int info;
};
BSTNode::BSTNode()
{
	this->info = -1;
	this->left = this->right = this->parent = NULL;
}
BSTNode::BSTNode(int value)
{
	this->info = value;
	this->left = this->right = this->parent = NULL;
}
void BSTNode::setLeft(BSTNode* left)
{
	this->left = left;
}
void BSTNode::setRight(BSTNode* right)
{
	this->right = right;
}
void BSTNode::setParent(BSTNode* parent)
{
	this->parent = parent;
}
void BSTNode::setInfo(int info)
{
	this->info = info;
}
BSTNode* BSTNode::getLeft()
{
	return this->left;
}
BSTNode* BSTNode::getRight()
{
	return this->right;
}
BSTNode* BSTNode::getParent()
{
	return this->parent;
}
int BSTNode::getInfo()
{
	return this->info;
}

class BST
{
public:
	void insert(int value);
	BST();
	BSTNode* root;
	int i = 0;
	int length = 0;
	int* array = new int[length];
	void inorder(BSTNode* node);
};
BST::BST()
{
	this->root = NULL;
	array = new int[10];
}
void BST::insert(int value)
{
	BSTNode* p = root;
	BSTNode* prev = 0;

	// find a place for inserting new node
	while (p != 0 && root != 0)
	{
		prev = p;
		if (value < p->getInfo())
			p = p->getLeft();
		else
			p = p->getRight();
	}
	if (root == 0)                  // tree is empty
	{
		root = new BSTNode(value);
		length++;
	}
	else if (value < prev->getInfo())
	{
		BSTNode* temp = new BSTNode(value);
		temp->setParent(prev);
		prev->setLeft(temp);
		length++;
	}
	else
	{
		BSTNode* temp = new BSTNode(value);
		temp->setParent(prev);
		prev->setRight(temp);
		length++;
	}
}

void BST::inorder(BSTNode* BSTNode)
{
	if (BSTNode != NULL)
	{
		inorder(BSTNode->getLeft());
		cout << BSTNode->getInfo() << "  ";
		array[i] = BSTNode->getInfo();
		i++;
		inorder(BSTNode->getRight());
	}
}



void BSTintersec(BST tree1, BST tree2)
{
	cout << "In Order traversal of 1st BST is: " << endl;
	tree1.inorder(tree1.root);
	cout << endl;

	cout << "In Order traversal of 2nd BST is: " << endl;
	tree2.inorder(tree2.root);
	cout << endl;

	int* array1 = new int[10];
	cout << "Intersection of first and second tree is: \n";
	for (int i = 0; i < tree1.length; i++)
	{
		for (int j = 0; j < tree2.length; j++)
		{
			if (tree1.array[i] == tree2.array[j])
			{
				array1[i] = tree1.array[i];
				cout << array1[i] << " ";
			}
		}
	}
	cout << endl;
}

int main()
{
	BST tree1;
	tree1.insert(10);
	tree1.insert(20);
	tree1.insert(23);
	tree1.insert(1);
	tree1.insert(2);
	tree1.insert(21);
	cout << endl;

	BST tree2;
	tree2.insert(15);
	tree2.insert(20);
	tree2.insert(25);
	tree2.insert(14);
	tree2.insert(22);
	tree2.insert(21);
	cout << endl;
	BSTintersec(tree1, tree2);
}
