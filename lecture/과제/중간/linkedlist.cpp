#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int value;
	struct Node* nextNode;
} Node;

typedef struct {
	int curcount;
	Node* headNode;
} Linkedlist;

void Initlist(Linkedlist* linkedlist) {
	linkedlist->headNode = (Node*)malloc(sizeof(Node));
	linkedlist->headNode->nextNode = NULL;
	linkedlist->curcount = 0;
}

int InsertFirst(Linkedlist* linkedlist, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	if (linkedlist->headNode == NULL)
	{
		printf("list is Null");
		return 0;
	}
	else
	{
		newNode->value = value;
		newNode->nextNode = linkedlist->headNode->nextNode;
		linkedlist->headNode->nextNode = newNode;
		linkedlist->curcount++;
	}

	return 1;
}

int InsertValue(Linkedlist* linkedlist, int value, int pos) {
	Node* per = (Node*)malloc(sizeof(Node));
	Node* cur = (Node*)malloc(sizeof(Node));

	if (linkedlist == NULL)
	{
		printf("list is Null");
		return 0;
	}
	else
	{
		per = linkedlist->headNode->nextNode;
		cur = per->nextNode;
	}

	while (pos)
	{
		per = cur;
		cur = cur->nextNode;
		pos--;
	}
	
	return 0;
}

// cur을 마지막까지 이동 후 newNode에 값을 입력 후 해당 Node를 nextNode로 지정하여 연결
int InsertLast(Linkedlist* linkedlist, int value) {
	Node* cur = (Node*)malloc(sizeof(Node));
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->value = value;
	cur = linkedlist->headNode;

	while (cur->nextNode != NULL) {
		cur = cur->nextNode;
	}

	cur->nextNode = newNode;
	linkedlist->curcount++;

	return 0;
}


void PrintNode(Linkedlist* linkedlist) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode = linkedlist->headNode->nextNode;
	printf("list ->");
	while (newNode != NULL) {
		printf("-> %d", newNode->value);
		newNode = newNode->nextNode;
	}
}

void DeleteNode(Linkedlist* linkedlist, int value) {
	Node* newNode = linkedlist->headNode;
	Node* newNode2 = newNode->nextNode;

	while (newNode2 != NULL) {
		if (newNode2->value == value)
		{
			newNode->nextNode = newNode2->nextNode;
			free(newNode2);
			linkedlist->curcount--;
			break;
		}
		else
		{
			newNode = newNode2;
			newNode2 = newNode2->nextNode;
		}
	}
}

void m123n() {
	Linkedlist list;

	Initlist(&list);

	InsertFirst(&list, 7);

	InsertFirst(&list, 3);
	
	InsertLast(&list, 9);

	DeleteNode(&list, 3);

	PrintNode(&list);
}