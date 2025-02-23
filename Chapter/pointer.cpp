#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 포인터 예제
void ex_pointer()
{
	int num, * ptr;
	num = 10;
	ptr = &num;

	printf("nNum = %d, &nNum = %p \n", num, (void*)&num);
	printf("pNum = %d, pNum = %p, &pNum = %p\n", *ptr, (void*)ptr, (void*)&ptr);
}

// 메모리 할당 예제
// malloc => 지정된 크기의 메모리를 할당 - 여기서는 100개의 정수를 저장할 수 있는 메모리 할당
// free => 할당된 메모리를 해제
int ex_memory() {
	int* buffer = NULL;  // NULL로 초기화

	buffer = (int*)malloc(100 * sizeof(int));  // 메모리 할당

	if (buffer == NULL) {
		printf("Memory allocation failed!\n");
		return -1;
	}

	free(buffer); // 할당된 메모리 해제
	return 0;
}

// 동적 메모리 할당 예제
int ex_memory2()
{
	int a, i;
	int* numbers;
	printf("input a: ");
	scanf("%d", &a);  // scanf_s 대신 scanf 사용

	// malloc을 사용하여 동적으로 메모리를 할당
	numbers = (int*)malloc(a * sizeof(int));

	if (numbers == NULL) {
		printf("Memory allocation failed!\n");
		return -1;
	}

	for (i = 0; i < 10; i++)
		numbers[i] = i;

	for (i = 0; i < 10; i++)
		printf("numbers[%d]: %d\n", i, numbers[i]);

	// 할당된 메모리 해제
	free(numbers);

	return 0;
}

// 2차원 배열 동적 메모리 할당 예제
int ex_memory3()
{
	int** matrix;
	int row, col, i, j;
	printf("input the row: ");
	scanf("%d", &row);  // scanf_s 대신 scanf 사용
	printf("input the col: ");
	scanf("%d", &col);

	// 행 크기만큼 포인터 배열을 동적 할당
	matrix = (int**)malloc(row * sizeof(int*));

	if (matrix == NULL) {
		printf("Memory allocation failed!\n");
		return -1;
	}

	// 각 행마다 열 크기만큼 동적 할당
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(col * sizeof(int));
		if (matrix[i] == NULL) {
			printf("Memory allocation failed!\n");
			return -1;
		}
	}

	// 2차원 배열 값 초기화
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix[i][j] = i * col + j;
		}
	}

	// 2차원 배열 출력
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	// 할당된 메모리 해제
	for (i = 0; i < row; i++) {
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}

// 구조체 예제
typedef struct person
{
	char* name;
	int age;
} PERSON;

int ex1()
{
	int size, k;
	PERSON* pPerson = NULL;
	char temp[256];
	size = 10;

	// 구조체 배열을 동적으로 할당
	pPerson = (PERSON*)malloc(sizeof(PERSON) * size);
	if (pPerson == NULL) {
		printf("Memory allocation failed!\n");
		return -1;
	}

	for (k = 0; k < size; k++) {
		printf("[%d]name : ", k);
		scanf("%s", temp);  // scanf_s 대신 scanf 사용

		// 이름을 저장할 메모리 동적 할당 (temp 크기만큼)
		pPerson[k].name = (char*)malloc(strlen(temp) + 1);

		if (pPerson[k].name == NULL) {
			printf("Memory allocation failed!\n");
			return -1;
		}

		// 입력받은 문자열을 할당된 메모리에 복사
		strcpy(pPerson[k].name, temp);  // strcpy_s 대신 strcpy 사용

		pPerson[k].age = rand() % 26;
	}

	// 저장된 정보 출력
	printf("\n");
	for (k = 0; k < size; k++) {
		printf("[%d]name: %s, age : %d\n", k, pPerson[k].name, pPerson[k].age);
	}

	// 할당된 메모리 해제
	for (k = 0; k < size; k++) {
		free(pPerson[k].name);
	}
	free(pPerson);

	return 0;
}
