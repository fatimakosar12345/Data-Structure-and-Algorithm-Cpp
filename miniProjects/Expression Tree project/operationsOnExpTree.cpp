#include<iostream>
#include<stack>

using namespace std;

int inputpre(char input)
{
	int num = 0;
	if (input == '+' || input == '-')
	{
		num = 1;
	}
	else if (input == '*' || input == '/' || input == '%')
	{
		num = 2;
	}
	else if (input == '^')
	{
		num = 5;
	}
	return num;
}
int outputpre(char input)
{
	int num = 0;
	if (input == '+' || input == '-')
	{
		num = 1;
	}
	else if (input == '*' || input == '/' || input == '%')
	{
		num = 2;
	}
	else if (input == '^')
	{
		num = 7;
	}
	return num;
}
string InfixToPostfix(string str)
{
	stack<char> s;
	string add = "";
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			add += str[i];
		}
		else if (s.empty())
		{
			s.push(str[i]);
		}
		else if (str[i] == '(' || s.top() == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (s.top() != '(')
			{
				add += s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while ((!s.empty() && (inputpre(s.top()) > outputpre(str[i]))))
			{
				add += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty())
	{
		add += s.top();
		s.pop();
	}
	return add;
}
void EvaluatePostfix(string str)
{
	int num1 = 0, num2 = 0, count = 0;
	int* val = new int[str.length()];
	char* ch = new char[str.length()];
	stack<int> s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			num2 = s.top();
			s.pop();
			num1 = s.top();
			s.pop();
			switch (str[i])
			{
			case '+':
				s.push(num1 + num2);
				break;
			case '-':
				s.push(num1 - num2);
				break;
			case '*':
				s.push(num1 * num2);
				break;
			case '/':
				s.push(num1 / num2);
				break;
			}
		}
		else
		{

			cout << "\nEnter variable " << str[i] << " value: ";
			cin >> val[count];
			ch[count] = str[i];
			str[i] = val[count];
			s.push(val[count]);
			count++;
		}
	}
	cout << "\n**************************************************************************************************\n";
	cout << "\nVariable values are: \n";
	for (int i = 0; i < count; i++)
	{
		cout << ch[i] << ":  " << val[i] << endl;
	}
	cout << endl;
	cout << "\n**************************************************************************************************\n";
	cout << "Final result is: ";
	cout << s.top() << endl;
	s.pop();
}
class TreeNode
{
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	char Info;
public:
	//constructor
	TreeNode(int val = 0)
	{
		Info = val;
		this->parent = this->left = this->right = NULL;
	}

	//setters
	void setparent(TreeNode* parent = NULL)
	{
		this->parent = parent;
	}
	void setleft(TreeNode* left = NULL)
	{
		this->left = left;
	}
	void setright(TreeNode* right = NULL)
	{
		this->right = right;
	}
	void setinfo(char Info)
	{
		this->Info = Info;
	}

	//getters
	TreeNode* getparent()
	{
		return this->parent;
	}
	TreeNode* getleft()
	{
		return this->left;
	}
	TreeNode* getright()
	{
		return this->right;
	}
	char getInfo()
	{
		return Info;
	}
};

class ExpTree
{
public:
	TreeNode* root;

	// constructor
	ExpTree()
	{
		root = NULL;
	}
	void insertion(string str)
	{
		stack<TreeNode*> s;
			
		for (int i = 0; i < str.length(); i++)
		{
			TreeNode* newnode = new TreeNode(str[i]);           // to create new node
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			{
				newnode->setright(s.top());           // to insert operators in inner node
				s.pop();
				newnode->setleft(s.top());            // to insert operators in inner node
				s.pop();

			}
			s.push(newnode);                        // to push node in stack
		}
		root = s.top();
		cout << "\n**************************************************************************************************\n";
		cout << "Expression tree has been created whose Inorder traversal is: \n";
		Inorder(root);
	}
	void Postorder(TreeNode* tree)
	{
		if (tree != NULL)
		{
			Postorder(tree->getleft());
			Postorder(tree->getright());
			cout << tree->getInfo();
		}
	}
	void ExpressionTree(string str)
	{
		insertion(InfixToPostfix(str));
	}
	void EvaluateExpTree(string str)
	{
		cout << "We are going to evaluate the following expression: \n";
		cout << str;
		cout << "\nPostfix order of expression " << str << " is " << InfixToPostfix(str);
		cout << "\n**************************************************************************************************\n";
		EvaluatePostfix(InfixToPostfix(str));
	}
	void Inorder(TreeNode* tree)              // for having operators precedence
	{
		if (tree != NULL)
		{
			if (tree->getleft() != NULL && tree->getright() != NULL)
				cout << "(";
			Inorder(tree->getleft());
			cout << tree->getInfo() << " ";
			Inorder(tree->getright());
			if (tree->getleft() != NULL && tree->getright() != NULL)
				cout << ")";
		}
	}

	// Function to display the Tree
	void display(TreeNode* tree, int level)
	{
		int i;
		if (tree != NULL)
		{
			display(tree->getright(), level + 1);
			cout << "\n";
			if (tree == root)
				cout << "Root -> ";
			for (i = 0; i < level && tree != root; i++)
				cout << "	 ";

			cout << tree->getInfo();
			display(tree->getleft(), level + 1);
		}
	}
};

void menu()
{
	ExpTree t;
	int choice;
	char option;
	string exp;
	do {
		cout << "\n**************************************************************************************************\n";
		cout << "\nFollowing are choices to implement the following functionalities: " << endl;
		cout << "\n**************************************************************************************************\n";
		cout << "\n1-> To convert infix expression into an expression tree";
		cout << "\n2-> To display the expression tree";
		cout << "\n3-> To evaluate expression tree and to display all variable values with final result\n";
		cout << "\n**************************************************************************************************\n";
		cout << "\nEnter your choice:  ";
		cin >> choice;
		cout << "\n**************************************************************************************************\n";
		if (choice == 1)
		{
			cout << "\nEnter Infix Expression:  ";
			cin >> exp;
			t.ExpressionTree(exp);
		}
		else if (choice == 2)
		{
			if (t.root == NULL)
				cout << "\nExpression tree is NULL";
			else
			{
				cout << "\nExpression tree is: \n";
				t.display(t.root, 1);
			}
		}
		else if (choice == 3)
		{
			t.EvaluateExpTree(exp);
		}
		else
		{
			cout << "You have entered invalid choice\n";
		}
		cout << "\n**************************************************************************************************\n";
		cout << "\nDo you want to continue(Y and y for yes & N and n for no):  ";
		cin >> option;
		while (!((option == 'y' || option == 'Y') || (option == 'n' || option == 'N')))
		{
			cout << "Enter valid choice:  ";
			cin >> option;
		}
	} while (option == 'y' || option == 'Y');
}

int main()
{
	menu();
}