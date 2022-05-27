#include <iostream>
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
void Tree::built_tree(char* arr, int index, int n)
{
	while (index < n)
	{
		add_node(root, arr[index]);
		index++;
	}
}

void Tree::add_node(Node* parent, char newChar)
{
	if (parent == NULL)
		parent = new Node(newChar);
	else if (newChar < parent->data)
	{
		if (parent->left == NULL)
			parent->left = new Node(newChar);
		else
			(parent->left, newChar);
	}
	else if (newChar > parent->data)
	{
		if (parent->right == NULL)
			parent->right = new Node(newChar);
		else
			(parent->right, newChar);
	}
	else
		parent->counter++;
}

void Tree::display_tree(Node* parent, int distance)
{

}

Node::Node(char ch)
{
	char data = ch;
	int counter = 0;
	Node* left = NULL;
	Node* right = NULL;
}
Node::~Node()
{
	delete left;
	delete right;
}