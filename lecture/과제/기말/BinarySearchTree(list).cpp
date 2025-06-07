#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key)
		{
			p->left;
		}
		else if (x == p->key)
		{
			return p;
		}
		else
		{
			p = p->right;
		}
	}
	printf("\n 찾는 키가 없습니다!");
	return p;
}

treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode;
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}
	else if (x < p->key)
	{
		p->left = insertNode(p->left, x);
	}
	else if (x > p->key)
	{
		p->right = insertNode(p->right, x);
	}
	else
	{
		printf("\n 이미 같은 키가 있습니다. \n");
	}

	return p;
}

void deleteNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key))
	{
		parent = p;
		if (key < p->key)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if (p == NULL)
	{
		printf("\n 찾는 키가 이진 트리에 없습니다.");
		return;
	}
	if ((p->left == NULL) && (p->right == NULL))
	{
		// 부모 노드가 존재 시
		if (parent != NULL) {
			// p가 부모 노드의 왼쪽 자식이면
			if (parent->left == p)
			{
				parent->left = NULL;
			}
			//  p가 부모 노드의 오른쪽 자식이면
			else
			{
				parent->right = NULL;
			}
		}
		else
		{
			root = NULL;
		}
	}
}