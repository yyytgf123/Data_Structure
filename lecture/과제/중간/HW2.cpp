#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef; // 계수
    int exp;  // 차수
    struct Node* next;
} Node;

// 노드 생성
Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// 뒤에 노드 추가
void insertNode(Node** head, int coef, int exp) {
    Node* newNode = createNode(coef, exp);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* cur = *head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = newNode;
    }
}

// 다항식 출력
void printPoly(Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coef, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

// 다항식 덧셈 연산
Node* addPoly(Node* A, Node* B) {
    Node* C = NULL; // 결과 다항식
    Node* p = A;
    Node* q = B;
    Node* r = NULL;

    while (p != NULL && q != NULL) {
        if (p->exp > q->exp) {
            insertNode(&C, p->coef, p->exp);
            p = p->next;
        }
        else if (p->exp < q->exp) {
            insertNode(&C, q->coef, q->exp);
            q = q->next;
        }
        else {
            int sumCoef = p->coef + q->coef;
            if (sumCoef != 0)
                insertNode(&C, sumCoef, p->exp);
            p = p->next;
            q = q->next;
        }
    }

    while (p != NULL) {
        insertNode(&C, p->coef, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        insertNode(&C, q->coef, q->exp);
        q = q->next;
    }

    return C;
}

int main() {
    Node* A = NULL;
    Node* B = NULL;
    Node* C = NULL;

    // A(x) = 3x^4 + 2x^3 + 1x^0
    insertNode(&A, 3, 4);
    insertNode(&A, 2, 3);
    insertNode(&A, 1, 0);

    // B(x) = 1x^3 + 2x^2 + 3x^0
    insertNode(&B, 1, 3);
    insertNode(&B, 2, 2);
    insertNode(&B, 3, 0);

    printf("A(x) = ");
    printPoly(A);

    printf("B(x) = ");
    printPoly(B);

    C = addPoly(A, B);

    printf("C(x) = A(x) + B(x) = ");
    printPoly(C);

    return 0;
}
