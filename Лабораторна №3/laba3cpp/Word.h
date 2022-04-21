#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

// розробити клас слово. створити масив обєктів даного типу.визначити слово з max к-стю цифр
class Word
{
	string word;
public:
	Word();
	Word(string word);
	string get_word();
	int calc_digits();
	//перевірити чи слово є словом
};
bool is_word(string str);
vector <Word> create_arr(int n);
void print_arr(vector <Word> arr);
vector <Word> word_with_max_number_of_digits(vector <Word> arr);