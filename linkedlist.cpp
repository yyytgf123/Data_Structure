#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE -1
#define TRUE 1

//�⺻ ���� ���� Node
typedef struct Node {
	int data;
	struct Node* nextNode;
}Node;

typedef struct LinkedList {
	int curCount; //�� List�� ����ִ� Node�� ��
	Node headNode; //List�� ���� Node
}LinkedList;

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
	addNode(linkedList, 2, 50);

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
	}

	pNewNode = (Node*)malloc(sizeof(Node));
	if (!pNewNode)
	{
		printf("addNode() error3 \n");
		return FALSE;
	}

	//�߰��� ��ġ ���� ���� �̵�
	pTmpNode = &(pList->headNode);
	for (i = 0; i < pos; i++)
	{
		pTmpNode = pTmpNode->nextNode;
	}

	//�߰� ����� nextNode = ���� ����� nextNode
	//���� ����� nextNode = �߰� ����� �ּ�
	pNewNode->nextNode = pTmpNode->nextNode;
	pTmpNode->nextNode = pNewNode;
	pList->curCount++;
	return TRUE;
}