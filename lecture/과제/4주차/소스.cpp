#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#define MAXSTRLEN 16

// 다항식의 항을 표현하는 노드 구조체
typedef struct _LISTNODE_ {
    int coef;   // 계수
    int expo;   // 차수
    struct _LISTNODE_* next;
} LISTNODE;

// 다항식 전체를 관리하는 구조체
typedef struct _LINKEDLIST_ {
    LISTNODE* head;
    int numOfData;
} LINKEDLIST;

// 연결 리스트 초기화
void InitList(LINKEDLIST* pList) {
    pList->head = (LISTNODE*)calloc(1, sizeof(LISTNODE));
    pList->head->next = NULL;
    pList->numOfData = 0;
}

// 연결 리스트 메모리 해제
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

// 리스트의 마지막에 새로운 노드 추가
void AddLast(LINKEDLIST* pList, int coef, int expo) {
    LISTNODE* newNode = (LISTNODE*)calloc(1, sizeof(LISTNODE));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->next = NULL;

    LISTNODE* pre = pList->head;
    LISTNODE* cur = pList->head->next;

    // 차수를 내림차순으로 정렬하면서 삽입
    while (cur != NULL && cur->expo > expo) {
        pre = cur;
        cur = cur->next;
    }

    // 같은 차수가 있는 경우 계수를 더함
    if (cur != NULL && cur->expo == expo) {
        cur->coef += coef;
        free(newNode);
        return;
    }

    newNode->next = cur;
    pre->next = newNode;
    pList->numOfData++;
}
// 다항식 출력
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

// 다항식의 덧셈
void addPoly(LINKEDLIST* A, LINKEDLIST* B, LINKEDLIST* C)
{
    LISTNODE* pA = A->head->next;  // A의 첫번째 항
    LISTNODE* pB = B->head->next;  // B의 첫번째 항

    while (pA && pB) {  // A와 B 모두 항이 남아있는 동안
        if (pA->expo > pB->expo) {  // A의 차수가 더 큰 경우
            AddLast(C, pA->coef, pA->expo);
            pA = pA->next;
        }
        else if (pA->expo < pB->expo) {  // B의 차수가 더 큰 경우
            AddLast(C, pB->coef, pB->expo);
            pB = pB->next;
        }
        else {  // A와 B의 차수가 같은 경우
            int sum = pA->coef + pB->coef;
            if (sum != 0) {  // 계수의 합이 0이 아닌 경우만 추가
                AddLast(C, sum, pA->expo);
            }
            pA = pA->next;
            pB = pB->next;
        }
    }

    // A에 남은 항들 처리
    while (pA) {
        AddLast(C, pA->coef, pA->expo);
        pA = pA->next;
    }

    // B에 남은 항들 처리
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

    // 메모리 해제
    FreeList(&polyA);
    FreeList(&polyB);
    FreeList(&polyC);

    return 0;
}
