#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

typedef char element;
typedef struct {
	element queue[SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear)
	{
		printf("Queue is empty!");
		return 1;
	}
	return 0;
}

int isFull(QueueType* Q) {
	if (Q->rear == SIZE - 1)
	{
		printf("Queue is full");
		return 1;
	}
	return 0;
}

void enQueue(QueueType* Q, element item) {
	if (isFull(Q))
	{
		printf("\n\n Stack is full \n");
		return;
	}
	Q->rear++;
	Q->queue[Q->rear] = item;
	return;
}

element deQueue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("\n\n Stack is empty \n");
		return 0;
	}
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

element peekkk(QueueType* Q) {
	if (isEmpty(Q))
	{
		printf("\n\n Stack is full");
		return 0;
	}
	else
	{
		return Q->queue[Q->front + 1];
	}
}

void printQ(QueueType* Q) {
	int i;
	printf("Queue : [ ");
	for (i = Q->front +1; i <= Q->rear; i++)
	{
		printf("%3c", Q->queue[i]);
	}
	printf(" ]");
}

void ex468486() {
	QueueType* Q1 = createQueue();
	element data;

	printf("\n *** 순차 큐 연산 *** \n");
	printf("\n 삽입 A >>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n 삽입 B >>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n 삽입 C >>"); enQueue(Q1, 'C'); printQ(Q1);

	data = peekkk(Q1); printf("peek item : %c \n", data);

	data = deQueue(Q1); printf("\t 삭제 데이터 : %c \n", data);
	printQ(Q1);
}