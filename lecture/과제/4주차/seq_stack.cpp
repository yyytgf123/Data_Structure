#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef int element; // int형으로 element 선언 -> 재활용

element stack[SIZE]; // int stack[SIZE]와 동일
int top = -1;

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isFull() {
	// top이 99일때 max size 100에서 -1해준 99와 동일 시 100으로 가득참 확인
	if (top == SIZE - 1) return 1;
	else return 0;
}

void push(element item) {
	if (isFull())
	{
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (isEmpty())
	{
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--]; // stack[top] 값 먼저 출력 후 top - 1
}

element peek() {
	if (isEmpty())
	{
		printf("\n\n Stack is Empty! \n");
		return 0;
	}
	else return stack[top];
}

void printStack() {
	int i;
	printf("\n STACK [");
	for (i = 0; i <= top; i++)
	{
		printf(" %d ", stack[i]);
	}
	printf("]");
}

void ex12311() {
	element item;
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek => %d", item);

	item = pop(); printStack();
	printf("pop => %d", item);

	item = pop(); printStack();
	printf("pop => %d", item);

	item = pop(); printStack();
	printf("pop => %d", item);
}