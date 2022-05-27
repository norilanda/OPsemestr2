#pragma once

class Node;
class Tree
{
	Node* root;
public:
	Tree();
	~Tree();
	void built_tree(char* arr, int index, int n);
	void add_node(Node* parent, char newChar);
	void display_tree(Node* parent, int distance);
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
	~Node();
	friend class Tree;
};
