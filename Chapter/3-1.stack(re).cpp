#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Stack {
	Node* top;
}Stack;

void init(Stack* st) {
	st->top = NULL;
}

int is_empty(Stack* st) {
	return (st->top == NULL);
}

void push(Stack* st, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->link = st->top;
	st->top = temp;
}

int pop(Stack* st) {
	if (is_empty(st))
	{
		printf("Stack is empty");
		return -1;
	}
	else
	{
		Node* temp = st->top;
		int data = temp->data;
		st->top = temp->link;
		free(temp);
		return data;
	}
}

void print_stack(Stack* s) {
	for (Node* p = s->top; p != NULL; p = p->link)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}

int main()
{
	Stack s;
	init(&s);
	push(&s, 11); print_stack(&s);
	push(&s, 22); print_stack(&s);
	push(&s, 33); print_stack(&s);
	push(&s, 44); print_stack(&s);

	printf("Popped : %d\n", pop(&s));
	printf("Popped : %d\n", pop(&s));
	printf("Popped : %d\n", pop(&s));
	print_stack(&s);
	printf("Popped : %d\n", pop(&s));
	print_stack(&s);
	return 0;
}