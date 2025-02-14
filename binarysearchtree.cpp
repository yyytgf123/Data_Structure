#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

void insertTreeNode(Node**, int value);
void printTreePreorder(Node* pNode);
void printTreeInorder(Node* pNode);
void printTreePostorder(Node* pNode);

Node* searchTreeNode(Node* p, int value);
Node* searchTreeParentNode(Node* p, int value);
void deleteTreeNode(Node** p, int value);

int main()
{
	Node* pParentNode = NULL;

	insertTreeNode(&pParentNode, 4);
	insertTreeNode(&pParentNode, 2);
	insertTreeNode(&pParentNode, 6);
	insertTreeNode(&pParentNode, 1);
	insertTreeNode(&pParentNode, 3);
	insertTreeNode(&pParentNode, 5);
	insertTreeNode(&pParentNode, 7);

	printf("Tree(pParentNode)\n");
	printf("Preorder\t:");
	printTreePreorder(pParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(pParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(pParentNode);
	printf("\n\n");

	printf("Search Data3\n");
	if (searchTreeNode(pParentNode, 3) != NULL)
	{
		printf("3 is existed\n\n");
	}
	else
	{
		printf("3 is not existed\n\n");
	}

	printf("Delete data 3\n");
	deleteTreeNode(&pParentNode, 3);
	printf("Delete data 2\n");
	deleteTreeNode(&pParentNode, 2);

	printf("Search Data 3\n");
	if (searchTreeNode(pParentNode, 3) != NULL)
	{
		printf("3 is existed\n\n");
	}
	else
	{
		printf("3 is not existed\n\n");
	}

	printf("Tree(pParentNode)\n");
	printf("Preorder\t:");
	printTreePreorder(pParentNode);
	printf("\nInorder\t\t:");
	printTreeInorder(pParentNode);
	printf("\nPostorder\t:");
	printTreePostorder(pParentNode);
	printf("\n\n");

	return 0;
};

Node* searchTreeNode(Node* p, int value)
{
	while (p != NULL && p->data != value)
	{
		if (p->data < value)
		{
			p = p->rightChild;
		}
		else if (p->data > value)
		{
			p = p->leftChild;
		}
	}
	return p;
}

Node* searchTreeParentNode(Node* p, int value)
{
	Node* parentNode = NULL;
	while (p != NULL && p->data != value)
	{
		parentNode = p;
		if (p->data < value)
		{
			p = p->rightChild;
		}
		else
		{
			p = p->leftChild;
		}
	}
	return parentNode;
}

void deleteTreeNode(Node** p, int value)
{
	Node* parentNode;
	Node* delNode;
	Node* childNode;
	Node* succNode;

	parentNode = searchTreeParentNode(*p, value);
	delNode = searchTreeNode(*p, value);

	if (delNode==NULL)
	{
		printf("There is no %d\n", value);
		return;
	}

	//��� 1. �ڽ� ��尡 �ϳ��� ���� ���
	if ((delNode->leftChild == NULL) && (delNode->rightChild == NULL))
	{
		//�����尡 root�� ���
		if (parentNode == NULL)
		{
			(*p) = NULL;
		}
		else
		{
			//���� ��尡 �θ� ����� ��� �������� Ȯ�� �� ����
			if (parentNode->leftChild == delNode)
			{
				parentNode->leftChild = NULL;
			}
			else
			{
				parentNode->rightChild = NULL;
			}
		}
	}
	//��� 2. �ڽ� ��尡 �ϳ� �ִ� ���
	else if ((delNode->leftChild == NULL) || (delNode->rightChild == NULL))
	{
		//���� ����� �ڽ� ��带 childNode, ������ �̿��� ����Ŵ
		childNode = (delNode->leftChild != NULL) ? delNode->leftChild : delNode->rightChild;
		//���� ��尡 root�� ���
		if (parentNode == NULL)
		{
			(*p) = childNode;
		}
		else
		{
			//���� ��尡 �θ� ����� ��� �ʿ� �ִ��� Ȯ���ϰ� �ڽ� ��� ����
			if (parentNode->leftChild == delNode)
			{
				parentNode->leftChild = childNode;
			}
			else
			{
				parentNode->rightChild = childNode;
			}
		}
		free(delNode);
	}
	//��� 3. �ڽ� ��尡 �� �� �ִ� ���
	else
	{
		succNode = delNode->rightChild;
		while (succNode->leftChild != NULL)
		{
			parentNode = succNode;
			succNode = succNode->leftChild;
		}
		delNode->data = succNode->data;
		parentNode->leftChild = succNode->rightChild;
		delNode = succNode;
	}
	free(delNode);
}


