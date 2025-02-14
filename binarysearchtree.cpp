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

	//경우 1. 자식 노드가 하나도 없는 경우
	if ((delNode->leftChild == NULL) && (delNode->rightChild == NULL))
	{
		//지울노드가 root인 경우
		if (parentNode == NULL)
		{
			(*p) = NULL;
		}
		else
		{
			//지울 노드가 부모 노드의 어느 방향인지 확인 후 삭제
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
	//경우 2. 자식 노드가 하나 있는 경우
	else if ((delNode->leftChild == NULL) || (delNode->rightChild == NULL))
	{
		//지울 노드의 자식 노드를 childNode, 변수를 이용해 가르킴
		childNode = (delNode->leftChild != NULL) ? delNode->leftChild : delNode->rightChild;
		//지울 노드가 root인 경우
		if (parentNode == NULL)
		{
			(*p) = childNode;
		}
		else
		{
			//지울 노드가 부모 노드의 어느 쪽에 있는지 확인하고 자식 노드 연결
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
	//경우 3. 자식 노드가 둘 다 있는 경우
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


