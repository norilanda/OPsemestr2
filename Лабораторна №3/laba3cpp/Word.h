#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

// ��������� ���� �����. �������� ����� ����� ������ ����.��������� ����� � max �-��� ����
class Word
{
	string word;
public:
	Word(string word);
	string get_word();
	int calc_digits();
	//��������� �� ����� � ������
};
bool is_word(string str);
vector<Word> create_arr(int n);
void print_arr(vector<Word>arr);
int word_with_max_number_of_digits(vector<Word>arr);