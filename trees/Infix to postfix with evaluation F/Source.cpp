#include<iostream>
using namespace std;

class node {
private:
	int data;
	node* next;
public:
	node(int value = 0) {
		data = value;
		next = nullptr;
	}
	friend class stack;
};

class stack {
private:
	int length;
	node* top;
public:
	stack() {
		length = 0;
		top = NULL;
	}
	void push(int value) {
		node* newNode = new node(value);
		newNode->next = top;
		top = newNode;
	}
	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	int pop() {
		if (isEmpty()) {
			cout << "\nStack is already empty!\n";
			return 0;
		}
		else {
			int data = top->data;
			node* del = top;
			top = top->next;
			delete del;
			return data;
		}
	}
	int peek() {
		if (isEmpty()) {
			cout << "\nStack is already empty!\n";
			return -1;
		}
		else {
			return top->data;
		}
	}
	void display() {
		cout << "\nDisplay:\n";
		node* temp = top;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int check(char opt) {
	if (opt == '^') {
		return 3;
	}
	else if (opt == '/' || opt == '*') {
		return 2;
	}
	else if (opt == '+' || opt == '-') {
		return 1;
	}
	else {
		return -1;
	}
}

//(A/B-C)+(A+B-C)

void infixToPostfix(string str) {
	stack s;
	string des = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			des += str[i];
		}
		else if (str[i] == '(') {
			s.push(str[i]);
		}

		else if (str[i] == ')') {
			while (!s.isEmpty() && s.peek() != '(') {
				des += s.peek();
				s.pop();
			}
			if (!s.isEmpty()) {
				s.pop();
			}
		}
		else {
			while (!s.isEmpty() && check(char(s.peek())) > check(str[i])) {
				des += char(s.peek());
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.isEmpty()) {
		des += s.peek();
		s.pop();
	}
	cout << endl << des << endl;
}

void evaluatePostFix(string str) {
	stack s;
	for (int i = 0; i < str.length(); i++)
	{

		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
			int num1 = s.pop();
			int num2 = s.pop();
			switch (str[i]) {
			case '+':
				s.push(num1 + num2);
				break;
			case '-':
				s.push(num1 - num2);
				break;
			case '/':
				s.push(num1 / num2);
				break;
			case '*':
				s.push(num1 * num2);
				break;
			}
		}
		else {
			s.push(int(str[i] - '0'));
		}
	}
	cout << endl;
	cout << s.pop();
}

int main() {
	stack s;
	cout << "Push:\n";
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.display();

	cout << "\nPop:" << s.pop() << endl;

	s.display();

	evaluatePostFix("453*+");
	cout << endl;

	infixToPostfix("9-9/8");

}

