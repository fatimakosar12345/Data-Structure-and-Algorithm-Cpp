#include<iostream> 
#include<vector>       //header file for vectors operations
#include<string>
#include<fstream>      //header file for file handling
#include<iterator>     //header file for using iterators
#include<stack>       //header file for stack operations

using namespace std;
// Funtion for matching HTML tags
bool isHtmlMatched(const vector<string>& tags) {
	stack<string> S;     //Stack for opening tags
	stack<string> M;     //Stack for not matching opening tags

	typedef vector<string>::const_iterator Iter;      //iterator used to point out the contents of a container

	cout << "Matching tags: \n";
	for (Iter p = tags.begin(); p != tags.end(); ++p)       //use of iterator loop
	{
		if (p->at(1) != '/')           //condition for opening tags
			S.push(*p);
		else               //for clossing tag
		{
			if (S.empty())
				return false;          //to terminate function if stack is empty
			string open = S.top().substr(1);           //varaible open consist of opening tag present at top of S stack

			string close = p->substr(2);             //varaible consist of closing tag

			if (open.compare(close) != 0)            //if open and close have not matched
			{
				cout << "\n" << S.top() << " and " << *p << " are not matching tags\n";
				M.push(S.top());              //tag at top of S stack is pushed in M stack
				S.pop();                      //tag at top of S stack is poped
				if (S.empty())                //after poping if S stack is empty
				{
					cout << "\nThere is missing opening tag of " << *p << endl;
				}
				else
				{
					open = S.top().substr(1);           //varaible open consist of opening tag present at top of S stack
					if (open.compare(close) == 0)        
					{

						cout << "\nThere is missing closing tag of " << M.top() << endl;
					}
					else            //if open and close have not matched
					{
						cout << "\nThere is missing starting tag of " << *p << endl;
					}
				}
				return false;            //to terminate function if there is an unmatched tag
			}
			else                 //if open and close have matched
			{
				cout << S.top() << " " << *p << endl;           //to display matched opening and closing tags
				S.pop();                 //to pop from S stack 
			}
		}
		if (S.empty())
			return true;
	}
}
// Function for extracting html tags from .html file
void getHtmlTags()
{
	vector<string> tags;            //vector for storing tags
	string file_name;             //variable for file name to be read
	cout << "Plz enter file name:   ";
	cin >> file_name;
	cout << endl;
	ifstream read_file;
	read_file.open(file_name);         //to open file

	while (!read_file.eof())        //loop will continue untill there is not end of file
	{
		string line;             //varaible to store file data line by line
		getline(read_file, line);           //to read file data line by line

		int pos = 0;
		int ts = line.find("<", pos);       //varaible consist of position of < of a tag
		while (ts != string::npos)          //loop will continue untill there is no < of a tag
		{
			int te = line.find(">", ts + 1);        //variable consist of position of > of a tag
			tags.push_back(line.substr(ts, te - ts + 1));         //a tag is pushed into tags
			pos = te + 1;                 //pos is updated with position after > of the tag
			ts = line.find("<", pos);     //varaible consist of position of < of next tag
		}

	}
	cout << "Tags in HTML Page:\n";
	for (int i = 0; i < tags.size(); i++)          //loop to display stored tags in tags vector
	{
		cout << tags[i] << endl;
	}

	cout << endl;
	//for getting output if html tags have matched or not
	if (isHtmlMatched(tags))         //if html tags in file have matched or isHtmlMatched(tags) will return true
	{
		cout << "\nThere is no missing tag" << endl;
		cout << "Tags of HTML document has matched\n";
	}
	else                 //if html tags in file have not matched or isHtmlMatched(tags) will return false
		cout << "\nTags of HTML document has not matched\n";
	read_file.close();          //opened file has been closed
}
// main function
int main()
{
	getHtmlTags();          //function calling for getting html tags
}