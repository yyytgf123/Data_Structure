#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

// ArrayList 구조체 정의
typedef struct {
	int* data; // 동적 배열을 저장할 포인터
	int size; // 현재 저장된 요소 개수
	int capacity; // 배열의 총 크기 (동적으로 증가)
} ArrayList;

// 초기화 함수
void initArrayList(ArrayList* list) {
	list->capacity = INITIAL_CAPACITY;
	list->data = (int*)malloc(list->capacity * sizeof(int)); // 초기 크기 할당
	list->size = 0; // 초기 크기는 0
}

// 크기 조정 함수 (배열 크기를 두 배로 증가)
void resizeArrayList(ArrayList* list) {
	list->capacity *= 2; // 용량을 두 배로 증가
	list->data = (int*)realloc(list->data, list->capacity * sizeof(int)); // 재할당
}

// 요소 추가 함수
void add(ArrayList* list, int value) {
	if (list->size == list->capacity) // 배열이 꽉 찼다면 크기 증가
	{
		resizeArrayList(list);
	}
	list->data[list->size++] = value; // 새로운 요소 추가 후 size 증가
}

// 특정 인덱스의 요소 제거 함수
void removeAt(ArrayList* list, int index) {
	if (index < 0 || index >= list->size) // 유효한 인덱스인지 확인
	{
		printf("잘못된 인덱스입니다.\n");
		return;
	}
	for (int i = index; i < list->size - 1; i++) // 요소를 한 칸씩 앞으로 이동
	{
		list->data[i] = list->data[i + 1];
	}
	list->size--; // 요소 개수 감소
}

// 특정 인덱스의 요소 가져오기 함수
int get(ArrayList* list, int index) {
	if (index < 0 || index >= list->size) // 유효한 인덱스인지 확인
	{
		printf("인덱스 범위를 벗어났습니다.\n");
		return -1;
	}
	return list->data[index]; // 해당 인덱스의 값 반환
}

// 현재 저장된 요소 개수 반환 함수
int size(ArrayList* list) {
	return list->size;
}

// 동적 메모리 해제 함수
void destroyArrayList(ArrayList* list) {
	free(list->data); // 동적 메모리 해제
	list->data = NULL;
	list->size = 0;
	list->capacity = 0;
}

int main() {
	ArrayList list;
	initArrayList(&list); // ArrayList 초기화

	add(&list, 10);
	add(&list, 20);
	add(&list, 30);
	add(&list, 40);
	add(&list, 50);
	
	int currentSize = size(&list);
	printf("Current size : %d\n", currentSize);

	printf("ArrayList 크기 : %d\n", size(&list));
	printf("인덱스 2의 요소 : %d\n", get(&list, 2));

	removeAt(&list, 1); // 인덱스 1의 요소 제거
	printf("인덱스 1 제거 후 크기 : %d\n", size(&list));
	printf("새로운 인덱스 1의 요소 : %d\n", get(&list, 1));

	destroyArrayList(&list); // 메모리 해제
	return 0;
}
