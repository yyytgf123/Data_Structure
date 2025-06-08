#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p;
	p = root;
	while (p != NULL)
	{
		if (x < p->key)
		{
			p = p->left;
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

treeNode* insertNode(treeNode* p, char x)
{
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

void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	// p�� null�� �ƴϰ� ���� ���� ������ ���� ã�� ���� �۾�
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

	// ���� �۾�
	// 1. ������ ��尡 ���� ���
	if (p == NULL)
	{
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL))
	{
		// �θ� �ִ� ���
		if (parent != NULL)
		{
			// �θ��� ���� ���� ���������� �Ǵ� �� ����
			if (parent->left == p)
			{
				parent->left = NULL;
			}
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

	// ������ ��� p�� �ڽ� ��� �ϳ��� ���� ���
	else if ((p->left == NULL) || (p->right == NULL))
	{
		// p�� �ڽ��� ����, ������ ��� �������� Ȯ��
		if (p->left != NULL)
		{
			child = p->left;
		}
		else
		{
			child = p->right;
		}

		// �θ� �����ϴ� ���, p�� parent�� ��� ���⿡ �ִ��� Ȯ��
		// �Ʒ� �ڵ� ���� �� ����
		//// parent -> p -> child
		// �Ʒ� �ڵ� ���� �� ����
		//// parent -> child
		// => �� p�� ����
		if (parent != NULL)
		{
			if (parent->left == p)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
		}
		else root = child;
	}
	
	// ������ ��尡 �ڽ� ��� 2���� ���� ���
	else
	{
		succ_parent = p;
		succ = p->left;
		
		// Ʈ������ ���� ��忡�� ���� ū ���� ������
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}

		// ó������ ������ �ڽ��� ���� ���
		if (succ_parent->left == succ)
		{
			succ_parent->left = succ->left;
		}
		else
		{
			succ_parent->right = succ->left;
		}
		p->key = succ->key;
		p = succ;
	}
	free(p);
}


