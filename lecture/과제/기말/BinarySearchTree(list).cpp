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
	printf("\n ã�� Ű�� �����ϴ�!");
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
		printf("\n �̹� ���� Ű�� �ֽ��ϴ�. \n");
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
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�.");
		return;
	}
	if ((p->left == NULL) && (p->right == NULL))
	{
		// �θ� ��尡 ���� ��
		if (parent != NULL) {
			// p�� �θ� ����� ���� �ڽ��̸�
			if (parent->left == p)
			{
				parent->left = NULL;
			}
			//  p�� �θ� ����� ������ �ڽ��̸�
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