#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

// ArrayList ����ü ����
typedef struct {
	int* data; // ���� �迭�� ������ ������
	int size; // ���� ����� ��� ����
	int capacity; // �迭�� �� ũ�� (�������� ����)
} ArrayList;

// �ʱ�ȭ �Լ�
void initArrayList(ArrayList* list) {
	list->capacity = INITIAL_CAPACITY;
	list->data = (int*)malloc(list->capacity * sizeof(int)); // �ʱ� ũ�� �Ҵ�
	list->size = 0; // �ʱ� ũ��� 0
}

// ũ�� ���� �Լ� (�迭 ũ�⸦ �� ��� ����)
void resizeArrayList(ArrayList* list) {
	list->capacity *= 2; // �뷮�� �� ��� ����
	list->data = (int*)realloc(list->data, list->capacity * sizeof(int)); // ���Ҵ�
}

// ��� �߰� �Լ�
void add(ArrayList* list, int value) {
	if (list->size == list->capacity) // �迭�� �� á�ٸ� ũ�� ����
	{
		resizeArrayList(list);
	}
	list->data[list->size++] = value; // ���ο� ��� �߰� �� size ����
}

// Ư�� �ε����� ��� ���� �Լ�
void removeAt(ArrayList* list, int index) {
	if (index < 0 || index >= list->size) // ��ȿ�� �ε������� Ȯ��
	{
		printf("�߸��� �ε����Դϴ�.\n");
		return;
	}
	for (int i = index; i < list->size - 1; i++) // ��Ҹ� �� ĭ�� ������ �̵�
	{
		list->data[i] = list->data[i + 1];
	}
	list->size--; // ��� ���� ����
}

// Ư�� �ε����� ��� �������� �Լ�
int get(ArrayList* list, int index) {
	if (index < 0 || index >= list->size) // ��ȿ�� �ε������� Ȯ��
	{
		printf("�ε��� ������ ������ϴ�.\n");
		return -1;
	}
	return list->data[index]; // �ش� �ε����� �� ��ȯ
}

// ���� ����� ��� ���� ��ȯ �Լ�
int size(ArrayList* list) {
	return list->size;
}

// ���� �޸� ���� �Լ�
void destroyArrayList(ArrayList* list) {
	free(list->data); // ���� �޸� ����
	list->data = NULL;
	list->size = 0;
	list->capacity = 0;
}

int main() {
	ArrayList list;
	initArrayList(&list); // ArrayList �ʱ�ȭ

	add(&list, 10);
	add(&list, 20);
	add(&list, 30);
	add(&list, 40);
	add(&list, 50);
	
	int currentSize = size(&list);
	printf("Current size : %d\n", currentSize);

	printf("ArrayList ũ�� : %d\n", size(&list));
	printf("�ε��� 2�� ��� : %d\n", get(&list, 2));

	removeAt(&list, 1); // �ε��� 1�� ��� ����
	printf("�ε��� 1 ���� �� ũ�� : %d\n", size(&list));
	printf("���ο� �ε��� 1�� ��� : %d\n", get(&list, 1));

	destroyArrayList(&list); // �޸� ����
	return 0;
}
