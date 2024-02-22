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
	void preorder(BSTNode* node);
	void postorder(BSTNode* node);
	void inorder(BSTNode* node);
	BSTNode* findMin(BSTNode* Node);
	BSTNode* findMax(BSTNode* Node);
	bool search(int value);
	BSTNode* remove(BSTNode* tree, int info);
};
BST::BST()
{
	this->root = NULL;
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
		root = new BSTNode(value);
	else if (value < prev->getInfo())
	{
		BSTNode* temp = new BSTNode(value);
		temp->setParent(prev);
		prev->setLeft(temp);
	}
	else
	{
		BSTNode* temp = new BSTNode(value);
		temp->setParent(prev);
		prev->setRight(temp);
	}
}
BSTNode* BST::remove(BSTNode* tree, int info)
{
	BSTNode* node;
	int cmp = info - tree->getInfo();
	if (cmp < 0)
	{
		node = remove(tree->getLeft(), info);
		tree->setLeft(node);
	}
	else if (cmp > 0)
	{
		node = remove(tree->getRight(), info);
		tree->setRight(node);
	}

	else if (tree->getLeft() != NULL && tree->getRight() != NULL)
	{
		BSTNode* minNode;
		minNode = findMin(tree->getRight());
		tree->setInfo(minNode->getInfo());
		node = remove(tree->getRight(),
			minNode->getInfo());
		tree->setRight(node);
	}
	else
	{
		BSTNode* nodeToDelete = tree;
		if (tree->getLeft() == NULL)
			tree = tree->getRight();
		else if (tree->getRight() == NULL)
			tree = tree->getLeft();
		else tree = NULL;

		delete nodeToDelete;
	}
	return tree;
}
void BST::preorder(BSTNode* BSTNode)
{
	if (BSTNode != NULL)
	{
		cout << BSTNode->getInfo() << "  ";
		preorder(BSTNode->getLeft());
		preorder(BSTNode->getRight());
	}
}
void BST::postorder(BSTNode* BSTNode)
{
	if (BSTNode != NULL)
	{
		postorder(BSTNode->getLeft());
		postorder(BSTNode->getRight());
		cout << BSTNode->getInfo() << "  ";
	}
}
void BST::inorder(BSTNode* BSTNode)
{
	if (BSTNode != NULL)
	{
		inorder(BSTNode->getLeft());
		cout << BSTNode->getInfo() << "  ";
		inorder(BSTNode->getRight());
	}
}
BSTNode* BST::findMin(BSTNode* Node)
{
	if (Node == NULL)
		return NULL;
	if (Node->getLeft() == NULL)
		return Node;              // this is it
	return findMin(Node->getLeft());
}
BSTNode* BST::findMax(BSTNode* Node)
{
	if (Node == NULL)
		return NULL;
	if (Node->getRight() == NULL)
		return Node;              // this is it
	return findMax(Node->getRight());
}
bool BST::search(int value)
{
	BSTNode* p = root;
	while (p != 0)
	{
		if (value == p->getInfo())
			return true;
		else if (value < p->getInfo())
			p = p->getLeft();
		else
			p = p->getRight();
	}
	return 0;
}

int main()
{
	BST mybst;
	mybst.insert(10);
	mybst.insert(20);
	mybst.insert(23);
	mybst.insert(1);
	mybst.insert(2);
	mybst.insert(21);
	cout << endl;
	cout << "Pre Order " << endl;
	mybst.preorder(mybst.root);
	cout << endl;
	cout << "Post Order " << endl;
	mybst.postorder(mybst.root);
	cout << endl;
	cout << "In Order " << endl;
	mybst.inorder(mybst.root);
	cout << endl;
	cout << "Minimum value:  " << mybst.findMin(mybst.root)->getInfo() << endl;
	cout << "Maximum value:  " << mybst.findMax(mybst.root)->getInfo() << endl;
	cout << "Searching 30 in the tree returned:  " << mybst.search(30) << endl;
	mybst.remove(mybst.root, 2);
	cout << "After removing 2 from tree In Order display is: " << endl;
	mybst.inorder(mybst.root);
}