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
	printf("\n 찾는 키가 없습니다!");
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
		printf("\n 이미 같은 키가 있습니다. \n");
	}
	
	return p;
}

void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	// p가 null이 아니고 지울 값과 동일할 값을 찾기 위한 작업
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

	// 삭제 작업
	// 1. 삭제할 노드가 없는 경우
	if (p == NULL)
	{
		printf("\n 찾는 키가 이진 트리에 없습니다!!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL))
	{
		// 부모가 있는 경우
		if (parent != NULL)
		{
			// 부모의 왼쪽 인지 오른쪽인지 판단 후 삭제
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

	// 삭제할 노드 p가 자식 노드 하나를 갖는 경우
	else if ((p->left == NULL) || (p->right == NULL))
	{
		// p의 자식이 왼쪽, 오른쪽 어느 방향인지 확인
		if (p->left != NULL)
		{
			child = p->left;
		}
		else
		{
			child = p->right;
		}

		// 부모가 존재하는 경우, p가 parent의 어느 방향에 있는지 확인
		// 아래 코드 동작 전 구조
		//// parent -> p -> child
		// 아래 코드 동작 후 구조
		//// parent -> child
		// => 즉 p를 삭제
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
	
	// 삭제할 노드가 자식 노드 2개를 갖는 경우
	else
	{
		succ_parent = p;
		succ = p->left;
		
		// 트리에서 왼쪽 노드에서 가장 큰 값을 가져옴
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}

		// 처음부터 오른쪽 자식이 없는 경우
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


