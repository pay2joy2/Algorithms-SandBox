#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>

using namespace std;

struct tree
{
	int data;
	tree *left;
	tree *right;
};
void vvod(tree** node,int x)
{
	if (*node == NULL) 
	{
		*node = new tree;
		(*node)->data = x;
		(*node)->left = NULL;
		(*node)->right = NULL;
	}
	else if (x < (*node)->data)
	{
		if ((*node) != NULL)
		{
			vvod(&((*node)->left), x);
		}
		else
		{
			(*node)->left = new tree;
			(*node)->left->data = x;
			(*node)->left->left = (*node)->right->right = NULL;
		}
	}
	else if (x > (*node)->data)
	{
		if ((*node) != NULL)
		{
			vvod(&((*node)->right), x);
		}
		else
		{
			(*node)->right = new tree;
			(*node)->right->data = x;
			(*node)->right->right = (*node)->left->left = NULL;
		}
	}
}
void func(tree* node, int *count)
{
	if (node != NULL)
	{
		if (node->left != NULL || node->right != NULL)
		{

			func(node->left, count);
			func(node->right, count);
		}
		else
		{
			(*count)++;
		}
	}
}
int main() {
	tree* node = NULL;
	int x;
	while (cin >> x) {
		vvod(&node, x);
	}
	int count = 0;
	func(node, &count);
	cout << count;
	return 0;
}
