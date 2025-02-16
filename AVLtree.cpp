#include <stdio.h>
#include <stdlib.h>
#define Max(x,y) ((x)>(y)?(x):(y))

typedef struct AvlNode {
	int data;
	struct AvlNode* left, * right;
	int Height;
}AvlNode;

int height(AvlNode* node) {
	if (node == NULL)
	{
		return -1;
	}
	else
	{
		return node->Height;
	}
}

AvlNode* rotateLL(AvlNode* parent) {
	AvlNode* child = parent->left;
	parent = child->right;
	child->right = parent;

	parent->Height = Max(height(parent->left), height(parent->right)) + 1;
	child->Height = Max(height(child->left), parent->Height) + 1;
		
	return child;
}