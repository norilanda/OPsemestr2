#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"

using namespace std;

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	delete root;
}

void Tree::add_node(char ch)
{
	add_node_recursion(root, ch);
}

void Tree::add_node_recursion(Node* &parent, char newChar)
{
	if (parent == NULL)
		parent = new Node(newChar);		
	else if (newChar < parent->data)
	{
		if (parent->left == NULL)
			parent->left = new Node(newChar);
		else
			add_node_recursion(parent->left, newChar);
	}
	else if (newChar > parent->data)
	{
		if (parent->right == NULL)
			parent->right = new Node(newChar);
		else
			add_node_recursion(parent->right, newChar);
	}
}

void Tree::print_tree()
{
	print_node_pre_order(root, 0);
}
void Tree::print_node_pre_order(Node* &parent, int level)
{
	char space = ' ';
	char under = '_';
	for (int i = 0; i < level; i++)
		cout << string(3, space) << "|";
	cout << string(2, under);
	if (parent != NULL)
	{
		cout << parent->data << "\n";
		print_node_pre_order(parent->right, level + 1);
		print_node_pre_order(parent->left, level + 1);
	}
	else
		cout << "\n";
}

int Tree::search_char_level(char ch)
{
	int n = search_recursion(root, ch, 0);
	return n;
}
int Tree::search_recursion(Node*& parent, char ch, int level)
{
	if (parent == NULL)
		return -1;
	else if (parent->data == ch)
		return level;
	else if (ch < parent->data)
		return search_recursion(parent->left, ch, level + 1);
	else
		return search_recursion(parent->right, ch, level + 1);	
}

Node::Node(char ch)
{
	data = ch;
	left = NULL;
	right = NULL;
}
Node::~Node()
{
	delete left;
	delete right;
}