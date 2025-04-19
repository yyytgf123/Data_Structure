#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct stackNode {
	element data;
	stackNode* link;
} stackNode;

stackNode* top;

int isEmptyy() {
	if (top == NULL) return 1;
	else return 0;
}

void pushh(element data) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = data;
	temp->link = top; // 기존의 top을 연결
	top = temp; // temp가 top이 됌
}

element popp() {
	element item;
	stackNode* temp = top;

	if (top == NULL)
	{
		printf("\n\n Stack is empty \n");
		return 0;
	}

	item = temp->data;
	top = temp->link;
	free(temp);
	return item;
}

element peekk() {
	if (top == NULL)
	{
		printf("\n\n Stack is empty \n");
		return 0;
	}
	else
	{
		return top->data;
	}
}

void printStackk() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

void EX77778() {
	element item;
	top = NULL;
	printf("\n ** 연결 스택 연산 ** \n");
	printStackk();
	pushh(1); printStackk();
	pushh(2); printStackk();
	pushh(3); printStackk();

	item = peekk(); printStackk();
	printf("peek => %d", item);
	
	item = popp(); printStackk();
	printf("\t pop => %d", item);

	item = popp(); printStackk();
	printf("\t pop => %d", item);
}