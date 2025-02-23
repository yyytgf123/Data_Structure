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
	parent->left = child->right;
	child->right = parent;

	parent->Height = Max(height(parent->left), height(parent->right)) + 1;
	child->Height = Max(height(child->left), parent->Height) + 1;
		
	return child;
}

AvlNode* rotateRR(AvlNode* parent) {
	AvlNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	parent->Height = Max(height(parent->right), height(parent->left)) + 1;
	child->Height = Max(height(child->right), parent->Height) + 1;
	
	return child;
}

AvlNode* rotateLR(AvlNode* parent) {
	AvlNode* child = parent->left;
	parent->left = rotateRR(child);
	return rotateLL(parent);
}

AvlNode* rotateRL(AvlNode* parent)
{
	AvlNode* child = parent->right;
	parent->right = rotateLL(child);
	return rotateRR(parent);
}

AvlNode* avlAdd(AvlNode* root, int data) {
	if (root == NULL) {
		root = (AvlNode*)malloc(sizeof(AvlNode));
		if (root == NULL)
		{
			exit(1);
		}
		root->data = data;
		root->Height = 0;
		root->left = root->right = NULL;
	}

	else if (data < root->data)
	{
		root->left = avlAdd(root->left, data);

		if (height(root->left) - height(root->right) == 2)
		{
			if (data < root->left->data)
			{
				root = rotateLL(root);
			}
			else
			{
				root = rotateLR(root);
			}
		}
	}

	else if (data > root->data)
	{
		root->right = avlAdd(root->right, data);
	
		if (height(root->right) - height(root->left) == 2)
		{
			if (data > root->right->data) 
			{
				root = rotateRR(root);
			}
			else 
			{
				root = rotateRL(root);
			}
		}
	}

	else {
		printf("�ߺ� Ű ����");
		exit(1);
	}
	root->Height = Max(height(root->left), height(root->right)) + 1;
	return root;
}

AvlNode* avlSearch(AvlNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->data) return node;
	else if (key < node->data)
	{
		return avlSearch(node->left, key);
	}
	else if (key > node->data)
	{
		return avlSearch(node->right, key);
	}
}

AvlNode* inorderTraveling(AvlNode* root) {
	if (root != NULL)
	{
		inorderTraveling(root->left);
		printf("[%d]", root->data);
		inorderTraveling(root->right);
	}
	return 0;
}

int ex9() {
	
	AvlNode* root = NULL;
	
	root = avlAdd(root, 7);
	root = avlAdd(root, 8);
	root = avlAdd(root, 9);
	root = avlAdd(root, 2);
	root = avlAdd(root, 1);
	root = avlAdd(root, 5);
	root = avlAdd(root, 3);
	root = avlAdd(root, 6);
	root = avlAdd(root, 4);

	printf("�˻� : %d\n", avlSearch(root, 4)->data);
	printf("\n");
	inorderTraveling(root);
	return 0;
}











