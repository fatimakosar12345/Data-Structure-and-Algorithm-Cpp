#include<iostream>
#include<fstream>
#include<stack>
#include<string>
using namespace std;

class MatchingWords {
public:
	MatchingWords()
	{

	}
	int rolling(int count, string text, string pattern)
	{
		int sum2 = 0;
		for (int i = count; i < pattern.length() + count; i++)
		{
			if (i == text.length())
				break;
			sum2 += text[i];                      // to add the ASCII code of text in file upto pattern length
		}
		return sum2;
	}

	void matching(string patt, stack<string> line)
	{
		string text;                       // varaible to store file data line by line
		while (!line.empty())
		{
			text += line.top();
			line.pop();
		}
		bool cond = false;                        // bool variable that will return true if pattern will the data of file
		int count = 0, sum1 = 0, c = 0;

		for (int i = 0; i < patt.length(); i++)
		{
			sum1 += patt[i];                      // to add the ASCII of pattern step by step
		}

		for (int i = 0; i < text.length(); i++)
		{
			int sum = 0;
			int j = 0;
			sum = rolling(count, text, patt);
			if (sum1 == sum)                     // condition that if pattern string sum will be equal to text data string sum
			{
				for (int i = count; i < patt.length() + count; i++)
				{
					if (patt[j] == text[i])
					{
						cond = true;             // condition will be true if pattern will match the data character by character
						if (patt[j] == '.' || patt[j] == ',' || patt[j] == ':' || patt[j] == ';')
						{
							cond = true;
							continue;
						}
						if (i == count)
						{
							i = i - 1;
							if (i == -1)
								i++;
							else if (text[i] != ' ')     // for having space at front of word
							{
								cond = false;
								i++;
								continue;
							}
							else
								i++;
						}
						if (i == patt.length() + count - 1)
						{
							if (text[patt.length() + count] != ' ')      // for having space at end of word
								cond = false;
							if (text[patt.length() + count] == ',' || text[patt.length() + count] == '.' || text[patt.length() + count] == ':' || text[patt.length() + count] == ';')
								cond = true;
						}
					}
					else
						cond = false;

					j++;                        // to increament pattern index
				}
			}
			if (cond)
			{
				c++;                   // if both pattern string and data string will be matched then it's occurances will be counted
			}
			cond = false;
			count++;                  // to increament text index for hash rolling
		}
		cout << "\n************************************************************************************************************************************************************************\n";
		cout << "\nNo of occurance of " << patt << " in above data is" << ": " << c << "\n\n";
		cout << "\n************************************************************************************************************************************************************************\n";
	}

	void MatchingFromFile()
	{
		string line;                      // varaible to store data line by line
		string str = "";                  // to store all data
		fstream FileName;
		FileName.open("DSA.txt");
		stack<string> s;
		if (!FileName)
			cout << "File does not exist\n";
		else
		{
			cout << "\n Following data is present in the file: \n";
			cout << "\n************************************************************************************************************************************************************************\n";
			while (!FileName.eof())
			{
				getline(FileName, line);           // to read file data line by line
				s.push(line);                       // to store all data in a string
				cout << line << endl;
			}
		}

		FileName.close();
		string data;                     // pattern data variable to be matched
		int choice = 0;               // variable to continue loop
		do {
			cout << "\n************************************************************************************************************************************************************************\n";
			cout << "\nEnter the word whose number of occurance you want to know in the above data:  ";
			cin >> data;
			cout << endl;
			matching(data, s);
			cout << "\nDo you want to search more words in the data(1 for yes and 0 for no):  ";
			
			cin >> choice;
			while (!(choice == 0 || choice == 1))
			{
				cout << "\n************************************************************************************************************************************************************************\n";
				cout << "\nEnter valid choice:  ";
				cin >> choice;
			}
		} while (choice == 1);
	}
};

int main()
{
	MatchingWords obj;
	obj.MatchingFromFile();
}