#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Queue {
    int data[SIZE];
    int front, rear;
} Queue;

void init(Queue* q) {
    q->front = q->rear = 0;
}

int empty(Queue* q) {
    return q->front == q->rear;
}

int isFull(Queue* q) {
    return q->front == (q->rear + 1) % SIZE;
}

void push(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % SIZE;
}

int pop(Queue* q) {
    if (empty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    return value;
}

int size(Queue* q) {
    return (q->rear - q->front + SIZE) % SIZE;
}

int front(Queue* q) {
    if (empty(q)) return -1;
    return q->data[q->front];
}

int back(Queue* q) {
    if (empty(q)) return -1;
    return q->data[(q->rear - 1 + SIZE) % SIZE];
}

int main() {
    Queue q;
    init(&q);

    char command[10];
    int command2;

    while (1) {
        printf("\npush x, pop, size, front, back, exit : ");
        scanf_s("%s", command);

        if (strcmp(command, "push") == 0) {
            scanf_s("%d", &command2);
            push(&q, command2);
            printf("Pushed: %d\n", command2);
        }
        else if (strcmp(command, "pop") == 0) {
            if (!empty(&q)) {
                int value = pop(&q);
                printf("Popped: %d\n", value);
            }
            else {
                printf("Queue is empty!\n");
            }
        }
        else if (strcmp(command, "size") == 0) {
            printf("Queue size: %d\n", size(&q));
        }
        else if (strcmp(command, "front") == 0) {
            if (!empty(&q)) {
                printf("Front: %d\n", front(&q));
            }
            else {
                printf("Queue is empty!\n");
            }
        }
        else if (strcmp(command, "back") == 0) {
            if (!empty(&q)) {
                printf("Back: %d\n", back(&q));
            }
            else {
                printf("Queue is empty!\n");
            }
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exit.\n");
            break;
        }
        else {
            printf("Try again\n");
        }
    }
    return 0;
}
