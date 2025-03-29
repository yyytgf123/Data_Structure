#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* nextNode;
} Node;

typedef struct {
	int curCount;
	Node* headNode;
} LinkedList;

void InitNode(LinkedList* linkednode) {
	linkednode->headNode = (Node*)malloc(sizeof(Node));
	linkednode->headNode->nextNode = NULL;
	linkednode->curCount = 0;
}

int Add_Node(LinkedList* linkednode, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (linkednode == NULL) {
		printf("Add FristNode Fail\n");
		return -1;
	}

	newNode->data = data;

	newNode->nextNode = linkednode->headNode->nextNode;
	linkednode->headNode->nextNode = newNode;
	linkednode->curCount += 1;

	return 0;
}

void Del_List(LinkedList* linkednode, int num) {
	Node* per = linkednode->headNode, *cur = per->nextNode;
	
	while (cur != NULL) {
		if (cur->data == num) {
			per->nextNode = cur->nextNode;
			free(cur);
			cur = NULL;
			linkednode->curCount -= 1;
			break;
		}
		per = cur;
		cur = cur->nextNode;
	}
	
	return 0;
}

void Prt_List(LinkedList* linkednode) {	
	Node* cur = linkednode->headNode->nextNode;

	printf("HeadNode");
	while (cur != NULL) {
		printf(" -> %d", cur->data);
		cur = cur->nextNode;
	}

	return 0;
}

Node* Sch_Node(LinkedList* linkedlist, int num) {
	Node* cur = linkedlist->headNode->nextNode;

	while (cur != NULL) {
		if (cur->data == num) {
			return cur;
		}
		cur = cur->nextNode;
	}

	return NULL;
}

//num으로 위치를 받아와 더함
void Sum_List(LinkedList* linkednode, int num) {
	Node* per = (Node*)malloc(sizeof(Node)), *cur = (Node*)malloc(sizeof(Node));

	//list수보다 큰 경우 예외 처리
	if (num > linkednode->curCount -1) {
		printf("범위 초과\n");
		return 0;
	}

	per = linkednode->headNode;
	while (num) {
		cur = per->nextNode;
		per = cur;
		num--;
	}

	Node* list1 = per;
	Node* nextlist = per->nextNode;
	Node* list2 = nextlist;

	return(printf("Sum_List1 : %d\n", list1->data + list2->data));
}

//Sch_Node를 통해 2개의 노드를 받아와 더함
void Sum_List2(Node* list1, Node* list2) {
	int v1, v2;

	if (list1 != NULL)
		v1 = list1->data;
	else
		v1 = 0;
	if (list2 != NULL)
		v2 = list2->data;
	else
		v2 = 0;

	printf("Sum_List2 : %d\n", v1 + v2);

	return 0;
}


int main() {
	LinkedList list;
	Node *find = NULL, *find2 = NULL;

	//init
	InitNode(&list);

	//add
	Add_Node(&list, 1);
	Add_Node(&list, 2);
	Add_Node(&list, 3);
	Add_Node(&list, 4);
	Add_Node(&list, 5);
	Add_Node(&list, 6);

	//print
	Prt_List(&list);
	printf("\n");

	//find
	find = Sch_Node(&list, 3);
	if (find != NULL)
		printf("Search Value : %d\n", find->data);
	else
		printf("Find Value Fail\n");
	find2 = Sch_Node(&list, 7);
	if (find2 != NULL)
		printf("Search Value : %d\n", find2->data);
	else
		printf("Find Value Fail\n");

	//sum
	Sum_List(&list, 3);
	Sum_List2(find, find2);

	//del
	Del_List(&list, 5);

	//print
	Prt_List(&list);
}