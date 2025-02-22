#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	Node* lnext;
	Node* rnext;
	int data;
}Node;

typedef struct Listmask {
	Node* head; // list head만 가르킴
	Node* tail; // list tail만 가르킴
	int size;
}Listmask;

Listmask* init_list(void) {
	Listmask* ls = (Listmask*)malloc(sizeof(Listmask));

	ls->head = NULL;
	ls->tail = NULL;
	int size = 0;

	return ls;
}

void addfisrt(Listmask* ls, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;

	if (ls->head == NULL)
	{
		ls->head = ls->tail = temp;
		
		ls->head->lnext = temp; // 순환 연결 유지를 위함

		ls->head->rnext = temp; // 순환 연결 유지를 위함
	}
	else
	{
		temp->lnext = ls->head->lnext;

		temp->rnext = ls->head->rnext;

		ls->head->lnext = temp;

		ls->tail->rnext = temp;
	}
	ls->size++;
	
	return;
}

void addlast(Listmask* ls, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;

	if (ls->tail == NULL)
	{
		ls->head = ls->tail = temp;

		ls->tail->lnext = temp;

		ls->tail->rnext = temp;
	}
	else
	{
		temp->lnext = ls->tail->lnext;

		temp->rnext = ls->tail->rnext;
		
		ls->tail->rnext = ls->head;

		ls->head->lnext = ls->tail;
	}
	ls->size++;

	return;
}

void addPos(Listmask* ls, int pos, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	Node* cur;

	if (ls == NULL)
	{
		printf("value is null");
		return;
	}

	int last_pos = ls->size;
	
	temp->data = data;

	if (pos <= ls->size)
	{
		if (pos==1)
		{
			printf("Add_Pos -> Add_Frist");
			addfisrt(ls, data);
		}
		else if (pos==last_pos)
		{
			printf("Add_Pos -> Add_Last");
			addlast(ls, data);
		}
		else
		{
			int n = pos - 1;
			cur = ls->head;

			while (--n)
			{
				cur = cur->rnext;
			}
			temp->lnext = cur;
			temp->rnext = cur->rnext;

			cur->rnext = temp;
			temp->rnext->lnext = temp;

			++ls->size;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		}
	}
}