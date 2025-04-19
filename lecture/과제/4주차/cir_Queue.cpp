#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

// 원형 큐 구조는 [1] -> [2] -> [3] -> [4] -> [1] 로 말그대로 원형을 이룸
// 그래서 push, pop, print등 구조가 rear or front에서 + 1을 해줘서 확인

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
	QueueType* cQ = createQueuee();  // 큐 생성
	element data;
	printf("\n ***** 원형 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enQueuee(cQ, 'A'); printQQ(cQ);
	printf("\n 삽입 B>>"); enQueuee(cQ, 'B'); printQQ(cQ);
	printf("\n 삽입 C>>"); enQueuee(cQ, 'C'); printQQ(cQ);
	data = peekkkk(cQ); printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deQueuee(cQ); printQQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueuee(cQ); printQQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueuee(cQ); printQQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삽입 D>>"); enQueuee(cQ, 'D'); printQQ(cQ);
	printf("\n 삽입 E>>"); enQueuee(cQ, 'E'); printQQ(cQ);
}




