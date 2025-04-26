#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
} node;

typedef struct list {
	node* head;
} list;

list* init_list(list* l) {
	l = (list*)malloc(sizeof(list));
	l->head = NULL;
	return l;
}

void print_list(list* l) {
	node* temp = l->head;
	while (temp != NULL) {
		printf("%d", temp->data);
		temp = temp->next;
	}
	return;
}	

void insert_node(list* l, int data) {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;

	if (l->head == NULL) return;
	else
	{
		temp->next = l->head->next;
		l->head->next = temp;
	}
	return;
}

int search_node(list* l, int data) {
	node* temp = (node*)malloc(sizeof(node));
	temp = l->head;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			return temp->data;
		}
		temp = temp->next;
	}
}

void delete_node(list* l, node* n) {
	node* temp = (node*)malloc(sizeof(node));
	
	while (temp != NULL)
	{
		if (temp->data == n->data)
		{
			free(temp);
		}
		temp = temp->next;
	}
}

void main() {
	list list;
	init_list(&list);

	insert_node(&list, 4);
	print_list(&list);
}









