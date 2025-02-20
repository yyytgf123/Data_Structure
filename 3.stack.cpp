#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//구조체 선언
typedef struct StackNode {
	int data;
	struct StackNode* next;
} StackNode;

//함수
void pushLinkedStack(StackNode** top, int data);
StackNode* popLinkedStack(StackNode** top);
void showLinkedStack(StackNode* top);
StackNode* topLinkedStack(StackNode* top);
void deleteLinkedStack(StackNode** top);
int isEmpty(StackNode* top);

int ex4() {
	StackNode* top = NULL;
	StackNode* pNode;

	printf("Push(10,20,30) called.\n");
	pushLinkedStack(&top, 10);
	pushLinkedStack(&top, 20);
	pushLinkedStack(&top, 30);
	showLinkedStack(top);

	printf("Pop() called. \n");
	pNode = popLinkedStack(&top);
	if (pNode)
	{
		free(pNode);
		showLinkedStack(top);
	}

	printf("Top() called. \n");
	pNode = topLinkedStack(top);
	if (pNode)
	{
		printf("Top node's data: %d\n", pNode->data);
	}
	else {
		printf("The Stack is empty\n");
	}
	showLinkedStack(top);

	deleteLinkedStack(&top);
	return 0;
}

int isEmpty(StackNode* top)
{
	if (top == NULL)
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void pushLinkedStack(StackNode** top, int data)
{
	StackNode *pNode = NULL;

	//Stack노드를 할당, data값을 저장
	pNode = (StackNode*)malloc(sizeof(StackNode));
	pNode->data = data;
	pNode->next = NULL;
	
	//stack이 empty인 경우 top으로 지정
	if (isEmpty(*top))
	{
		*top = pNode;
	}
	else
	{
		//넣을 stack nod의 다음 노드가 현재 top node를 가르키고
		//top node를 넣을 stack node로 지정
		pNode->next = *top;
		*top = pNode;
	}
}

StackNode* popLinkedStack(StackNode** top)
{
	StackNode* pNode = NULL;

	//empty 확인
	if (isEmpty(*top))
	{
		printf("the Stack is empty\n");
		return NULL;
	}
	//pNode에 top이 가르키는 Node를 지정하고 top은 그 다음 Node로 지정
	pNode = *top;
	*top = pNode->next;


	return pNode;
}

void showLinkedStack(StackNode* top)
{
	StackNode* pNode = NULL;
	if (isEmpty(top))
	{
		printf("the Stack is empty\n");
		return;
	}

	pNode = top;
	printf("=====Show Stack=====\n");
	while (pNode != NULL)
	{
		printf("[%d]\n", pNode->data);
		pNode = pNode->next;
	}
	printf("====================\n");
}

StackNode* topLinkedStack(StackNode* top)
{
	StackNode* pNode = NULL;

	if (!isEmpty(top))
	{
		pNode = top;
	}
	return pNode;
}

void deleteLinkedStack(StackNode** top)
{
	StackNode* pNode = NULL, * pDelNode = NULL;
	pNode = *top;

	while(pNode != NULL)
	{
		pDelNode = pNode;
		pNode = pNode->next;
		free(pDelNode);
	}
	*top = NULL;
}