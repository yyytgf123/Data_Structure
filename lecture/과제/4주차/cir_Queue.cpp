#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

// ���� ť ������ [1] -> [2] -> [3] -> [4] -> [1] �� ���״�� ������ �̷�
// �׷��� push, pop, print�� ������ rear or front���� + 1�� ���༭ Ȯ��

typedef char element;
typedef struct {
	element queue[SIZE];
	int front, rear;
} QueueType;

QueueType* createQueuee() {
	QueueType* Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmptyy(QueueType* Q) {
	if (Q->front == Q->rear)
	{
		printf("\n\n Stack is empty \n");
		return 1;
	}
	return 0;
}

int isFulll(QueueType* Q) {
	if ((Q->rear + 1) % SIZE == Q->front)
	{
		printf("\n\n Stack is full");
		return 0;
	}
}

void enQueuee(QueueType* Q, element item) {
	if (isFulll(Q))
	{
		return;
	}
	else
	{
		Q->rear = (Q->rear + 1) % SIZE;
		Q->queue[Q->rear] = item;
	}
}

element deQueuee(QueueType* Q) {
	if (isEmptyy(Q))
	{
		return 1;
	}
	else
	{
		Q->front = (Q->front + 1) % SIZE;
		return Q->queue[Q->front];
	}
}

element peekkkk(QueueType* Q) {
	if (isEmptyy(Q))
	{
		exit(1);
	}
	else
	{
		return Q->queue[(Q->front + 1) % SIZE];
	}
}

void printQQ(QueueType* Q) {
	int i, first, last;
	first = (Q->front + 1) % SIZE;
	last = (Q->rear + 1) % SIZE;

	printf("Circular Queue : [ ");
	i = first;
	while (i != last) {
		printf("%3c", Q->queue[i]);
		i = (i + 1) % SIZE;
	}
	printf(" ]");
}

void main(void) {
	QueueType* cQ = createQueuee();  // ť ����
	element data;
	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>"); enQueuee(cQ, 'A'); printQQ(cQ);
	printf("\n ���� B>>"); enQueuee(cQ, 'B'); printQQ(cQ);
	printf("\n ���� C>>"); enQueuee(cQ, 'C'); printQQ(cQ);
	data = peekkkk(cQ); printf(" peek item : %c \n", data);
	printf("\n ���� >>"); data = deQueuee(cQ); printQQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueuee(cQ); printQQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueuee(cQ); printQQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ���� D>>"); enQueuee(cQ, 'D'); printQQ(cQ);
	printf("\n ���� E>>"); enQueuee(cQ, 'E'); printQQ(cQ);
}




