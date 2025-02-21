#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE -1
#define TRUE 1

typedef struct Node {
	int data;
	struct Node* nextNode;
};

void insert_Node(Node* head, int index, const int data) {
	int k = index;
	Node* pre_node = head;
	Node* insert = (Node*)malloc(sizeof(Node));
	insert->data = data;

	while (k-- && pre_node != NULL) {
		pre_node = pre_node->nextNode;
	}

	if (pre_node == NULL)
	{
		free(insert);
		return;
	}

	insert->nextNode = pre_node->nextNode;
	pre_node->nextNode = insert;
}

void delete_node(Node* head, const int index) {
	int k = index;
	Node* temp = head;
	Node* garbage = NULL;

	while (k-- && temp != NULL) {
		temp = temp->nextNode;
	}

	if (temp == NULL || temp->nextNode == NULL) 
	{
		return;
	}

	garbage = temp->nextNode;
	temp->nextNode = garbage->nextNode;
	free(garbage);
}

// val로 data를 받아옴
int search_node(Node* head, const int val) {
	if (head->nextNode == NULL) return -1;
	
	int index = 0;
	Node* temp = head->nextNode;

	while (temp->data != val) {
		++index;
		temp = temp->nextNode;
	
		if (temp == NULL) return -1;
	}
	return index;
}

int get_data(Node* head, const int index) {
	if (head->nextNode == NULL) return -1;
	
	int k = index;
	Node* temp = head->nextNode;

	while (k--) {
		temp = temp->nextNode;
	}

	return temp->data;
}

int size(Node* head) {
	Node* temp = head->nextNode;
	int len = 0;
	while (temp != NULL) {
		++len;
		temp = temp->nextNode;
	}
	return len;
}

void print_ll(Node* head) {
	if (head->nextNode == NULL) return;

	Node* temp = head->nextNode;

	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->nextNode;
	}
	printf("\n");
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->nextNode = NULL;

	insert_Node(head, 0, 123);
	print_ll(head); // expect 123

	insert_Node(head, 1, 10);
	print_ll(head); // expect 123 10

	insert_Node(head, 2, 20);
	print_ll(head); // expect 123 10 20

	insert_Node(head, 1, 11);
	print_ll(head); // expect 123 11 10 20

	insert_Node(head, 5, 19); // 길이를 넘어서는 인덱스를 전달해본다.
	print_ll(head); // expect 123 11 10 20

	printf("%d\n", search_node(head, 20)); // expext 3
	printf("%d\n", search_node(head, 11)); // expext 1
	printf("%d\n", size(head)); // expext 4
	printf("%d\n", get_data(head, 3)); // expext 20

	delete_node(head, 0);
	print_ll(head); // expext 11 10 20

	delete_node(head, 4); // 길이를 넘어서는 인덱스를 전달해본다.
	print_ll(head); // expext 11 10 20
}