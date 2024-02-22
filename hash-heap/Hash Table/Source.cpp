#include <iostream>
#include <string>
using namespace std;
class HashTree;
class Node
{
    string key;
    int val;

public:
    Node* next;
    Node(string key, int val) : key(key), val(val), next() {}
    Node* getNext() { return next; }
    int getVal() { return val; }
    string getKey() { return key; }
    friend class HashTree;
};

class HashTree
{
    Node** arr;
    int size; // size of the array
public:
    HashTree(int s = 10)
    {
        size = s;
        arr = new Node * [size];
        for (int i = 0; i < size; i++)
            arr[i] = new Node(".", 0); // dummy head nodes
    }
    void insert(string key, int val)
    {
        int index = hashFun(key);
        Node* temp = *(arr + index);
        Node* newNode = new Node(key, val);
        newNode->next = temp->next;
        temp->next = newNode;
        // *(arr+index )= new Node(key,val);
    }
    int hashFun(string key)
    {
        int code = 0;
        for (int i = 0; i < key.length(); i++)
            code += key[i];
        return (code % size);
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            Node* temp = arr[i]->next; // next
            cout << i << "   ";
            while (temp != NULL)
            {
                cout << "[ " << temp->key << " | " << temp->val << " ]";
                temp = temp->next;
                if (temp)
                    cout << " -> ";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    int search(string key)
    {
        int index = hashFun(key);
        Node* temp = *(arr + index);
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->getVal();
            }
            temp = temp->next;
        }
        return -1; // when not found
    }
    void remove(string key)
    {
        int index = hashFun(key);
        Node* prev = *(arr + index);
        Node* temp = prev->next;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void menu()
    {
        cout << "   MENU " << endl;
        cout << " 1- Insert a value in hashtable. " << endl;
        cout << " 2- Remove a value from hashtable. " << endl;
        cout << " 3- Display all values in hashtable. " << endl;
        cout << " 4- Search a value in the hashtable. " << endl;
        cout << " 5- Exit. " << endl;
    }
};

int main()
{
    HashTree tr;
    int val;
    string key;
    do
    {
        char choice = '\0';
        tr.menu();
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == '1')
        {
            cout << "Enter the key to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            tr.insert(key, val);
        }
        else if (choice == '2')
        {
            cout << "Enter key to remove: ";
            cin >> key;
            tr.remove(key);
        }
        else if (choice == '3')
        {
            tr.display();
        }
        else if (choice == '4')
        {
            cout << "Enter key to search: ";
            cin >> key;
            if (tr.search(key))
                cout << key << " found. " << endl;
            else
                cout << key << " not found. " << endl;
        }
        else if (choice == '5')
        {
            break;
        }
        else
        {
            cout << "Invalid choice !! " << endl;
        }
    } while (true);

    return 0;
}