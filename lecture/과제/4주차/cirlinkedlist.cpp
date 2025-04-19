#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* next;
};

typedef struct {
	Node* head;
} cir_list;

void init_list(cir_list* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL;
}

void insert_list(cir_list* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	if (list->head == NULL)
	{
		newNode->next = newNode;
		list->head = newNode;
	}
	else
	{
		Node* temp = list->head;
		while (temp != list->head) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = list->head;
	}
}

