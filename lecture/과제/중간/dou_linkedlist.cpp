#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* llink;
	Node* rlink;
} Node;

typedef struct {
	Node* head;
} list;

void init_Node(list* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->head->llink = NULL;
	list->head->rlink = NULL;
}

void insertNode(list* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (list->head == NULL)
	{
		list->head = newNode;
	}
	Node* temp = list->head;
	while (temp != NULL) {
		temp = temp->rlink;
	}
	temp->rlink = newNode;
	newNode->llink = temp;
}