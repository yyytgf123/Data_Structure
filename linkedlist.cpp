#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE -1
#define TRUE 1

//�⺻ ���� ���� Node
typedef struct Node {
	int data;
	struct Node* nextNode;
} Node;

typedef struct LinkedList {
	int curCount; //�� List�� ����ִ� Node�� ��
	Node headNode; //List�� ���� Node
} LinkedList;

int addNode(LinkedList* pList, int pos, int data);
int removeNode(LinkedList* pList, int pos);
void showNode(LinkedList* pList);
int isEmpty(LinkedList* pList);
int findPos(LinkedList* pList, int data);
void makeEmpty(LinkedList* pList);

int main()
{
	int pos;
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	linkedList->curCount = 0;
	linkedList->headNode.nextNode = NULL;

	showNode(linkedList);
	addNode(linkedList, 0, 10);
	addNode(linkedList, 5, 100);
	addNode(linkedList, 1, 20);
	addNode(linkedList, 2, 30);
	addNode(linkedList, 1, 50);

	showNode(linkedList);

	removeNode(linkedList, 1);
	showNode(linkedList);

	pos = findPos(linkedList, 30);
	printf("the location of node with data '30' : %d\n", pos);

	makeEmpty(linkedList);
	showNode(linkedList);
	return 0;
}

int addNode(LinkedList* pList, int pos, int data)
{
	int i = 0;
	Node* pNewNode = NULL, *pTmpNode = NULL;
	
	if (pList == NULL)
	{
		printf("addNode() error1 \n");
		return FALSE;
	}
	if (pos < 0 || pos > pList->curCount)
	{
		printf("addNode() error2: �߰� ���� �ʰ� \n");
		return FALSE;
	}

	pNewNode = (Node*)malloc(sizeof(Node));
	if (!pNewNode)
	{
		printf("addNode() error3 \n");
		return FALSE;
	}

	pNewNode->data = data;
	pNewNode->nextNode = NULL;

	//�߰��� ��ġ ���� ���� �̵�
	pTmpNode = &(pList->headNode);
	for (i = 0; i < pos; i++) {
		pTmpNode = pTmpNode->nextNode;
	}

	//�߰� ����� nextNode = ���� ����� nextNode
	//���� ����� nextNode = �߰� ����� �ּ�
	pNewNode->nextNode = pTmpNode->nextNode;
	pTmpNode->nextNode = pNewNode;
	pList->curCount++;
	return TRUE;
}

int removeNode(LinkedList* pList, int pos)
{
	int i = 0;
	Node* pDelNode = NULL, * pTmpNode = NULL;

	if (pList == NULL)
	{
		printf("removeNode() error1 \n");
		return FALSE;
	}


	if (pos < 0 || pos > pList->curCount)
	{
		printf("removceNode() error2 : ���� ���� �ʰ� \n");
		return FALSE;
	}
	
	//������ ��� ���� ��ġ�� �̵�
	pTmpNode = &(pList->headNode);
	for (i = 0; i < pos; i++)
	{
		pTmpNode = pTmpNode->nextNode;
	}

	//������ ��� = ���� ����� nextNode
	//���� ����� nextNode = ������ ����� nextNode
	pDelNode = pTmpNode->nextNode;
	pTmpNode->nextNode = pDelNode->nextNode;

	free(pDelNode);
	pList->curCount--;
	return TRUE;
}

void showNode(LinkedList* pList)
{
	int i = 0;
	Node* pNode = NULL;

	if (pList == NULL)
	{
		printf("showNode() error\n");
		return;
	}
	
	printf("current Node count : %d \n", pList->curCount);
	pNode = pList->headNode.nextNode;
	//pNode�� Linked List�� ������ ������ �̵��ϸ鼭 ���
	while (pNode != NULL)
	{
		printf("[%d]\n", pNode->data);
		pNode = pNode->nextNode;
	}
	printf("-------------\n");
}

int isEmpty(LinkedList* pList)
{
	if (pList == NULL)
	{
		printf("isEmpty() error\n");
		return -1;
	}

	//head ��尡 ����Ű�� next ��尡 �����ϴ°�
	if (pList->headNode.nextNode == NULL)
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int findPos(LinkedList* pList, int data)
{
	int pos = 0;
	Node* pNode = NULL;

	if (pList == NULL)
	{
		printf("findPos() error\n");
		return FALSE;
	}

	pNode = pList->headNode.nextNode;
	//������ ������ Ž��
	while (pNode != NULL)
	{
		//����� data�� ��ġ�Ѵٸ� �ش� ��ġ ��ȯ
		if (pNode->data == data)
		{
			return pos;
		}
		//ã�� ���� ��� ��ġ�� ������Ű�鼭 pNode�� �̵�
		pos++;
		pNode = pNode->nextNode;
	}
	return FALSE;
}

void makeEmpty(LinkedList* pList)
{
	Node* pDummyNode = NULL, * pTmpNode = NULL;
	if (pList != NULL) 
	{
		pTmpNode = pList->headNode.nextNode;
		//����Ǿ� �ִ� ��� ������ Ž��
		while (pTmpNode != NULL)
		{
			pDummyNode = pTmpNode;
			pTmpNode = pTmpNode->nextNode;
			free(pDummyNode);
		}
		return;
	}
}





