#include "Word.h"
using namespace std;

Word::Word() { cout << "Object is created\n"; }
Word::Word(string word)
{ 
	this->word = word;
}
string Word::get_word() 
{ 
	return word; 
}
int Word::calc_digits()
{
	int digits = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (isdigit(word[i]))
			digits++;
	}
	return digits;
}
bool is_word(string str)
{
	string acceptDelim = "'-`";
	bool isWord = true;
	int i = 0;
	while (isWord && i < str.length())
	{
		if (!isalnum(str[i]))
		{
			isWord = false;
			if (i > 0 && i < str.length())//check location
			{
				if (isalnum(str[i - 1]) && isalnum(str[i + 1]) && acceptDelim.find(str[i]) != string::npos)
					isWord = true;
			}
		}
		i++;
	}
	return isWord;
}
vector<Word> create_arr(int n)
{
	vector <Word> arr(n);

	for (int i = 0; i < n; i++)
	{
		cout << "Enter word: ";
		string str; getline(cin, str);
		while (!is_word(str))
		{
			cout << "You can enter only letters or digits. Try again: ";
			getline(cin, str);
		}
		arr[i] = Word(str);
	}
	return arr;
}
void print_arr(vector<Word>arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i].get_word() << endl;
	cout << "\n-----------------------------------------\n";
}
vector <Word> word_with_max_number_of_digits(vector <Word> arr)
{
	int maxNum = 0;
	vector <Word> maxDigitWords;
	for (int i = 0; i < arr.size(); i++)
	{
		int currentNum = arr[i].calc_digits();
		if (currentNum > maxNum)
		{
			maxDigitWords.clear();
			maxDigitWords.push_back(arr[i]);
			maxNum = currentNum;
		}
		else if (currentNum > 0 && currentNum == maxNum)
			maxDigitWords.push_back(arr[i]);
	}
	return maxDigitWords;
}