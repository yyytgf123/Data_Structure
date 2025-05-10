#include <stdio.h>
#include <stdlib.h>

// ���� ����Ʈ
typedef struct Node {
	int data;
	Node* next;
} Node;

typedef struct list {
	Node* head;
} list;

//// ������ x, �������� ����� ���� ����Ʈ
//typedef struct Node {
//	char data[4];
//	struct Node* next;
//} Node;
//
//Node* L;

// ���׽�
typedef struct poly_Node {
	int coef;
	int expo;
	poly_Node* next;
} poly_Node;

poly_Node* createNode(int coef, int expo) {
	poly_Node* newNode = (poly_Node*)malloc(sizeof(poly_Node));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->next = NULL;

	return newNode;
}

//// �� �� ����
void insertNode(poly_Node** node, int coef, int expo) {
	poly_Node* newNode = createNode(coef, expo);

	// ������ ���� ��ü�� addPoly�� c�� �ٲ�� �ϱ� ������ ���������� ���
	if (*node == NULL)
	{
		*node = newNode;
		return;
	}
	else {
		poly_Node* cur = *node;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

poly_Node* addPoly(poly_Node* a, poly_Node* b) {
	poly_Node* c = NULL;
	poly_Node* p = a;
	poly_Node* q = b;
	int r = 0;

	while (p != NULL && q != NULL) {
		if (p->expo > q->expo)
		{
			insertNode(&c, p->coef, p->expo);
			p = p->next;
		}
		if (p->expo < q->expo)
		{
			insertNode(&c, q->coef, q->expo);
			q = q->next;
		}
		else
		{
			int sumcoef = p->coef + q->coef;
			insertNode(&c, sumcoef, p->expo);
			p = p->next;
			q = q->next;
		}
	}
	while (p != NULL) {
		insertNode(&c, p->coef, p->expo);
		p = p->next;
	}
	while (q != NULL) {
		insertNode(&c, q->coef, q->expo);
		q = q->next;
	}

	return c;
}

void printNode(poly_Node* node) {
	while (node != NULL) {
		printf("%dx^%d", node->coef, node->expo);
		if (node->next != NULL) // ->next�ƴϸ� �������� + ����
		{
			printf(" + ");
		}
		node = node->next;
	}
	printf("\n");
}

int main() {
	poly_Node* A = NULL;
	poly_Node* B = NULL;
	poly_Node* C = NULL;

	insertNode(&A, 5, 4);
	insertNode(&A, 2, 3);
	insertNode(&A, 1, 2);
	insertNode(&A, 1, 0);

	insertNode(&B, 5, 6);
	insertNode(&B, -7, 4);
	insertNode(&B, 3, 3);
	insertNode(&B, -3, 2);

	printf("A(x) = ");
	printNode(A);

	printf("B(x) = ");
	printNode(B);

	C = addPoly(A, B);

	printf("C(x) = A(x) + B(x) = ");
	printNode(C);

	return 0;
}

// ���� ���Ḯ��Ʈ
typedef struct double_node {
	int data;
	double_node* llink;
	double_node* rlink;
} double_node;

// ���� ����
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {
	if (isFull())
	{
		return;
	}
	stack[++top] = item;
}

element pop(element item) {
	if (isEmpty())
	{
		return 1;
	}
	return stack[top--];
}

element peek() {
	if (isEmpty()) return 0;
	else return stack[top];
}

void printStack() {
	if (isEmpty()) return;
	for (int i = 0; i <= top; i++) {
		printf("%d", stack[top]);
	}
}

// ���� �ڷᱸ�� ����
typedef int element;

typedef struct stackNode {
	int data;
	Node* next;
} Node;

stackNode* linked_top;

int isEmpty() {
	if (linked_top == NULL) return 1;
	else return 0;
}

void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->next = linked_top;
	linked_top = temp;
}

element pop() {
	int temp;
	stackNode* temp2 = (stackNode*)malloc(sizeof(stackNode));

	if (isEmpty()) return 0;
	else
	{
		temp2 = linked_top;
		temp= temp2->data;
		linked_top = temp2->next;
		free(temp2);

		return temp;
	}
}

// ���� ť
#define Q_SIZE 4

typedef char element;
typedef struct {
	element queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType* cretaeQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) return 1;
	else return 0;
}

int isFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) return 1;
	else return 0;
}

void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;
	else
	{
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
	return;
}

element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return 0;
	else
	{
		// ������ ���� ���� ����Ű�� �ֱ⶧���� ++ ��, -1 -> 0 �ε���
		Q->front++;
		return Q->queue[Q->front];
	}
}






