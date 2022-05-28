#pragma once
#include <vector>

using std::vector;

class Node;
class Tree
{
	Node* root;
	void add_node(Node* &parent, char newChar);
	void print_node_pre_order(Node* &parent, int level);
	int search_recursion(Node*& parent, char ch, int level);
public:
	Tree();
	~Tree();
	void built_tree(vector <char> arr);
	void print_tree();
	int search_char_level(char ch);

	//search if such a node already exists
};

class Node
{
	char data;
	int counter;
	Node* left;
	Node* right;
public:
	Node(char ch);
	Node(Node& n);
	~Node();
	friend class Tree;
};
