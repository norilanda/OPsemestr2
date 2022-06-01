#pragma once
#include <vector>

using std::vector;
class Node;

class Tree
{
	Node* root;
	void add_node_recursion(Node* &parent, char newChar);
	void print_node_pre_order(Node* &parent, int level);
	int search_recursion(Node*& parent, char ch, int level);
public:
	Tree();
	~Tree();
	void add_node(char ch);
	void print_tree();
	int search_char_level(char ch);
};

class Node
{
	char data;
	Node* left;
	Node* right;
public:
	Node(char ch);
	~Node();
	friend class Tree;
};
