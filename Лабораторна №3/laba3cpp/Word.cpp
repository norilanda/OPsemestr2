#include "Word.h"
using namespace std;

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
	bool isWord = true;
	int i = 0;
	while (isWord && i < str.length())
	{
		if (!isalnum(str[i]))
			isWord = false;
	}
	return isWord;
}
vector<Word> create_arr(int n)
{
	vector <Word> arr(n);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter word: ";
		string str; cin >> str;
		while (!is_word(str))
		{
			cout << "You can enter only letters or digits. Try again: ";
			cin >> str;
		}
		arr[i] = Word(str);
	}
}
void print_arr(vector<Word>arr);
int word_with_max_number_of_digits(vector<Word>arr);