#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Functions.h"
#include "Tree.h"

using namespace std;

int main()
{
	//COUNTER!!!!!
	srand(time(0));
	int n;
	init_arr_size(n);
	vector <char> arr = enter_char_arr(n);
	Tree tree;
	for (int i = 0; i < n; i++)
		tree.add_node(arr[i]);

	cout << "\nCreated tree:\n";
	tree.print_tree();
	char ch = init_char();
	int level = tree.search_char_level(ch);
	if (level != -1)
		cout << "level of char" << ch << " = " << level << "\n";
	else
		cout << "There is no char " << ch << "\n";
}
