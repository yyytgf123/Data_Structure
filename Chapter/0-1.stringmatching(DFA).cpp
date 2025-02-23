#include <stdio.h>
#include <string.h>

#define MAX_PATTERN 100
#define R 256

int DFA[R][MAX_PATTERN]; // ���� ���� ���̺�

void buildDFA(char pattern[]) {
    int patLength = strlen(pattern);
    int X = 0; // ���� ���¸� �����ϴ� ����
    DFA[(int)pattern[0]][0] = 1; // ù ��° ���� ó��

    for (int j = 1; j < patLength; j++) {
        // ���� ���¿��� ������ ��� ���ڿ� ���� ���� ������ ���� ����
        for (int c = 0; c < R; c++) {
            DFA[c][j] = DFA[c][X];
        }
        // ���� ���� ���ڿ� ���� ���� ����
        DFA[(int)pattern[j]][j] = j + 1;

        // ���� ���� ����
        X = DFA[(int)pattern[j]][X];
    }
}

void printDFA(char pattern[]) {
    int patLength = strlen(pattern);
    printf("DFA Table:\n");
    for (int j = 0; j < patLength; j++) {
        printf("State %d: ", j);
        for (int c = 0; c < R; c++) {
            if (DFA[c][j] > 0) {
                printf("[%c -> %d] ", c, DFA[c][j]);
            }
        }
        printf("\n");
    }
}

int ex11() {
    char pattern[] = "ABABC";
    buildDFA(pattern);
    printDFA(pattern);
    return 0;
}
