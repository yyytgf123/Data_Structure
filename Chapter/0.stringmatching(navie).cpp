#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // malloc 사용을 위한 헤더 추가

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void naivematch(char T[], int n, char P[], int m, int output[]) {
    int i, j, k, kk;

    for (i = 0; i < n; i++) {
        output[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = i, k = 0; k < m && j < n; j++, k++) {
            if (T[j] != P[k])
                break;
        }

        for (j = i, kk = 0; kk < k; j++, kk++) {
            output[j] = MAX(output[j], kk + 1);
        }
    }
}

int ex10() {
    char text[] = "abcabcabc";
    char pattern[] = "abcd";
    int n = strlen(text);
    int m = strlen(pattern);

    // 동적 할당
    int* output = (int*)malloc(n * sizeof(int));

    naivematch(text, n, pattern, m, output);

    printf("Output array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(output);  // 동적 할당 해제

    return 0;
}