#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* lnext;
    struct Node* rnext;
    int data;
} Node;

typedef struct Listmask {
    Node* head;
    Node* tail;
    int size;
} Listmask;

Listmask* init_list(void) {
    Listmask* ls = (Listmask*)malloc(sizeof(Listmask));
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0; 
    return ls;
}

void addFirst(Listmask* ls, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;

    if (ls->head == NULL) {  
        ls->head = ls->tail = temp;
        ls->head->lnext = temp;
        ls->head->rnext = temp;
    }
    else {
        temp->lnext = ls->tail;
        temp->rnext = ls->head;
        ls->head->lnext = temp;
        ls->tail->rnext = temp;
        ls->head = temp;  // 
    }
    ls->size++;
}

void addLast(Listmask* ls, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;

    if (ls->tail == NULL) {  
        ls->head = ls->tail = temp;
        ls->tail->lnext = temp;
        ls->tail->rnext = temp;
    }
    else {
        temp->lnext = ls->tail;
        temp->rnext = ls->head;
        ls->tail->rnext = temp;
        ls->head->lnext = temp;
        ls->tail = temp;  
    }
    ls->size++;
}

// Ư�� ��ġ�� �߰�
void addPos(Listmask* ls, int pos, int data) {
    if (ls == NULL) {
        printf("Value is null\n");
        return;
    }

    int last_pos = ls->size;

    if (pos < 1 || pos > last_pos + 1) {  // pos�� last_pos + 1���� ����
        printf("You entered wrong position\n");
        return;
    }

    if (pos == 1) {
        printf("Add_Pos -> Add_First\n");
        addFirst(ls, data);
    }
    else if (pos == last_pos + 1) {  
        printf("Add_Pos -> Add_Last\n");
        addLast(ls, data);
    }
    else {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = data;

        Node* cur = ls->head;
        int n = pos - 1;

        while (--n) {
            cur = cur->rnext;
        }

        temp->lnext = cur;
        temp->rnext = cur->rnext;
        cur->rnext->lnext = temp;
        cur->rnext = temp;

        ls->size++;
    }
}

void deleteFirst(Listmask* ls) {
    if (ls->size == 0) {
        printf("List is already empty\n");
        return;
    }

    Node* temp = ls->head;

    if (ls->size == 1) {
        ls->head = NULL;
        ls->tail = NULL;
    }
    else {
        ls->head = temp->rnext;
        ls->head->lnext = ls->tail;
        ls->tail->rnext = ls->head;
    }

    free(temp);
    ls->size--;
}

void deleteLast(Listmask* ls) {
    if (ls->size == 0) {
        printf("List is already empty\n");
        return;
    }

    Node* temp = ls->tail;

    if (ls->size == 1) {
        ls->head = NULL;
        ls->tail = NULL;
    }
    else {
        ls->tail = temp->lnext;
        ls->tail->rnext = ls->head;
        ls->head->lnext = ls->tail;
    }

    free(temp);
    ls->size--;
}

// Ư�� ��ġ�� ��� ����
void deletePos(Listmask* ls, int pos) {
    if (ls == NULL || ls->head == NULL || pos < 1 || pos > ls->size) {
        printf("You entered wrong position.\n");
        return;
    }

    if (pos == 1) {
        deleteFirst(ls);
        return;
    }

    if (pos == ls->size) {
        deleteLast(ls);
        return;
    }

    Node* cur = ls->head;
    int n = pos - 1;

    while (n--) { 
        cur = cur->rnext;
    }

    Node* temp = cur;
    temp->lnext->rnext = temp->rnext;
    temp->rnext->lnext = temp->lnext;

    free(temp);
    ls->size--;
}

void printLIST(Listmask* ls) {
    if (ls->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* cur = ls->head;
    int n = ls->size;

    while (n--) {
        printf("%d ", cur->data);
        cur = cur->rnext;
    }
    printf("\n");
}

void retrunSize(Listmask* ls) {
    printf("\nCurrent list size is %d\n", ls->size);
}

int ex13() {
    // ����Ʈ �ʱ�ȭ
    Listmask* list = init_list();

    // ����Ʈ�� ��� �ִ� ���¿��� ũ�� Ȯ��
    retrunSize(list);
    printLIST(list);

    // ��� �߰� �׽�Ʈ
    printf("\nAdding elements...\n");
    addFirst(list, 10);
    addLast(list, 20);
    addLast(list, 30);
    addFirst(list, 5);
    addPos(list, 3, 15); // 3��° ��ġ�� 15 �߰�

    // ����Ʈ ��� �� ũ�� Ȯ��
    retrunSize(list);
    printLIST(list);

    // ���� �׽�Ʈ
    printf("\nDeleting first element...\n");
    deleteFirst(list);
    retrunSize(list);
    printLIST(list);

    printf("\nDeleting last element...\n");
    deleteLast(list);
    retrunSize(list);
    printLIST(list);

    printf("\nDeleting element at position 2...\n");
    deletePos(list, 2);
    retrunSize(list);
    printLIST(list);

    // ������ ���
    printf("\nFinal list state:\n");
    retrunSize(list);
    printLIST(list);

    free(list);

    return 0;
}
