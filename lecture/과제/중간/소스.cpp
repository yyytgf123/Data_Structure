#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#define MAXSTRLEN 16

// ���׽��� ���� ǥ���ϴ� ��� ����ü
typedef struct _LISTNODE_ {
    int coef;   // ���
    int expo;   // ����
    struct _LISTNODE_* next;
} LISTNODE;

// ���׽� ��ü�� �����ϴ� ����ü
typedef struct _LINKEDLIST_ {
    LISTNODE* head;
    int numOfData;
} LINKEDLIST;

// ���� ����Ʈ �ʱ�ȭ
void InitList(LINKEDLIST* pList) {
    pList->head = (LISTNODE*)calloc(1, sizeof(LISTNODE));
    pList->head->next = NULL;
    pList->numOfData = 0;
}

// ���� ����Ʈ �޸� ����
void FreeList(LINKEDLIST* pList) {
    LISTNODE* pre = pList->head;
    LISTNODE* cur = pList->head->next;

    while (cur != NULL) {
        pre = cur;
        cur = cur->next;
        free(pre);
    }
    free(pList->head);
    pList->head = NULL;
}

// ����Ʈ�� �������� ���ο� ��� �߰�
void AddLast(LINKEDLIST* pList, int coef, int expo) {
    LISTNODE* newNode = (LISTNODE*)calloc(1, sizeof(LISTNODE));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->next = NULL;

    LISTNODE* pre = pList->head;
    LISTNODE* cur = pList->head->next;

    // ������ ������������ �����ϸ鼭 ����
    while (cur != NULL && cur->expo > expo) {
        pre = cur;
        cur = cur->next;
    }

    // ���� ������ �ִ� ��� ����� ����
    if (cur != NULL && cur->expo == expo) {
        cur->coef += coef;
        free(newNode);
        return;
    }

    newNode->next = cur;
    pre->next = newNode;
    pList->numOfData++;
}
// ���׽� ���
void PrintPolynomial(LINKEDLIST* pList) {
    LISTNODE* cur = pList->head->next;

    if (cur == NULL) {
        printf("0\n");
        return;
    }

    int first = 1;
    while (cur != NULL) {
        if (!first) {
            printf(" + ");
        }

        if (cur->expo == 0) {
            printf("%d", cur->coef);
        }
        else {
            printf("%dx^%d", cur->coef, cur->expo);
        }

        first = 0;
        cur = cur->next;
    }
    printf("\n");
}

// ���׽��� ����
void addPoly(LINKEDLIST* A, LINKEDLIST* B, LINKEDLIST* C)
{
    LISTNODE* pA = A->head->next;  // A�� ù��° ��
    LISTNODE* pB = B->head->next;  // B�� ù��° ��

    while (pA && pB) {  // A�� B ��� ���� �����ִ� ����
        if (pA->expo > pB->expo) {  // A�� ������ �� ū ���
            AddLast(C, pA->coef, pA->expo);
            pA = pA->next;
        }
        else if (pA->expo < pB->expo) {  // B�� ������ �� ū ���
            AddLast(C, pB->coef, pB->expo);
            pB = pB->next;
        }
        else {  // A�� B�� ������ ���� ���
            int sum = pA->coef + pB->coef;
            if (sum != 0) {  // ����� ���� 0�� �ƴ� ��츸 �߰�
                AddLast(C, sum, pA->expo);
            }
            pA = pA->next;
            pB = pB->next;
        }
    }

    // A�� ���� �׵� ó��
    while (pA) {
        AddLast(C, pA->coef, pA->expo);
        pA = pA->next;
    }

    // B�� ���� �׵� ó��
    while (pB) {
        AddLast(C, pB->coef, pB->expo);
        pB = pB->next;
    }
}


int main() {
    LINKEDLIST polyA, polyB, polyC;
    InitList(&polyA);
    InitList(&polyB);
    InitList(&polyC);

    // polyA = 4x^3 + 3x^2 + 5x
    AddLast(&polyA, 4, 3);
    AddLast(&polyA, 3, 2);
    AddLast(&polyA, 5, 1);

    // polyB = 3x^4 + x^3 + 2x + 1
    AddLast(&polyB, 3, 4);
    AddLast(&polyB, 1, 3);
    AddLast(&polyB, 2, 2);
    AddLast(&polyB, 1, 0);

    printf("A(x) = ");
    PrintPolynomial(&polyA);
    printf("B(x) = ");
    PrintPolynomial(&polyB);

    addPoly(&polyA, &polyB, &polyC);
    printf("C(x) = A(x) + B(x) = ");
    PrintPolynomial(&polyC);

    // �޸� ����
    FreeList(&polyA);
    FreeList(&polyB);
    FreeList(&polyC);

    return 0;
}
