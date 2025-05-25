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
	
	while (p != NULL)
	{
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n ã�� Ű�� �����ϴ�!");
	return p;
}

treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode;
	// p�� ���� ��� node �����Ͽ� ����
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	// x�� �� ������� ���ʿ� ����
	else if (x < p->key)
	{
		p->left = insertNode(p->left, x);
	}
	// x�� �� ū ��� �����ʿ� ����
	else if (x > p->key)
	{
		p->right = insertNode(p->right, x);
	}
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;
}

void deleteNode(treeNode* root, element key) {
	treeNode* parent, *p, *succ, *succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	
	// ������ ����� ��ġ Ž��
	// p�� null, key���� ã���� ����
	while ((p != NULL) && (p->key != key)) {
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
	// ������ ��尡 ���� ���
	if (p == NULL)
	{
		printf("\n ã�� Ű�� ����Ʈ���� �����ϴ�.");
		return;
	}
	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL))
	{
		// parent�� NULL�� �ƴϸ�, �� �θ� �ִ� ���
		if (parent != NULL)
		{
			// while������ ã�� p�� ���� �θ��� ���ʰ� ���� �� left�� NULL
			if (parent->left == p)
			{
				parent->left = NULL;
			}
			// �ƴϸ� ������ ���� NULL
			else
			{
				parent->right = NULL;
			}
		}
		// �θ� NULL�̸� root ����̴� root�� null
		else root = NULL;
	}
	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else {
		// �ĺ� �ʱ�ȭ ����
		succ_parent = p;
		succ = p->left;
		// ���ʿ��� ���� ū ��� ã��
		// ���� �ڽ��� ������ ������ ������ -> ���� ū ��
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		// succ�� succ_parent�� ���� �ڽ����� ������ �ڽ����� �����Ͽ� ������ ����
		// succ�� �θ��� ���� �ڽ��� ���
		if (succ_parent->left == succ)
		{
			succ_parent->left = succ->left;
		}
		else
		{
			succ_parent->right = succ->left;
			p->key = succ->key;
			p = succ;
		}
	}
	free(p);
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ���
void displayInorder(treeNode* root) {
	if (root)
	{
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}