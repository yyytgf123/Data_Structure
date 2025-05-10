#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* nextnode;
} Node;

Node* L;

typedef struct {
	Node* headnode;
} linkedlist;

void initList(linkedlist* linkedlist) {
	linkedlist->headnode = (Node*)malloc(sizeof(Node));
	linkedlist->headnode->nextnode = NULL;
}

void addNode(linkedlist* linkedlist, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->nextnode = linkedlist->headnode->nextnode;
	linkedlist->headnode->nextnode = newNode;
}

void printNode(linkedlist* linkedlist) {
	Node* newNode = linkedlist->headnode->nextnode;

	printf("headNode");
	while (newNode != NULL) {
		printf(" -> %d", newNode->data);
		newNode = newNode->nextnode;
	}
}

void searchNode(int num) {

}

void deleteNode(linkedlist* linkedlist, int deletedata) {
	Node* newNode = linkedlist->headnode->nextnode;
	Node* tempNode = (Node*)malloc(sizeof(Node));

	while (newNode->nextnode != NULL) {
		if (newNode->nextnode->data == deletedata)
		{
			tempNode = newNode->nextnode->nextnode;
			newNode->nextnode = tempNode;
			free(tempNode);
			break;
		}
		newNode = newNode->nextnode;
	}
}

int main() {
	linkedlist list;

	initList(&list);
	addNode(&list, 1);
	addNode(&list, 2);
	addNode(&list, 3);
	addNode(&list, 4);

	deleteNode(&list, 3);

	printNode(&list);
}