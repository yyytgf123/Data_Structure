#include <stdio.h>
#include <string.h>

#define MAX_PATTERN 100
#define R 256

int DFA[R][MAX_PATTERN]; // 상태 전이 테이블

void buildDFA(char pattern[]) {
    int patLength = strlen(pattern);
    int X = 0; // 이전 상태를 저장하는 변수
    DFA[(int)pattern[0]][0] = 1; // 첫 번째 문자 처리

    for (int j = 1; j < patLength; j++) {
        // 현재 상태에서 가능한 모든 문자에 대해 이전 상태의 값을 복사
        for (int c = 0; c < R; c++) {
            DFA[c][j] = DFA[c][X];
        }
        // 현재 패턴 문자에 대한 전이 설정
        DFA[(int)pattern[j]][j] = j + 1;

        // 이전 상태 갱신
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
