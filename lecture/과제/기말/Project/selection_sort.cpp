#include <stdlib.h>
#include <stdio.h>

typedef int element;
int size;

void selectionSort(int a[], int size) {
	int i, j, t, min;
	element temp;
	printf("\n정렬할 원소 : ");
	for (t = 0; t < size; t++)
	{
		printf("%d", a[t]);
	}
	printf("\n\n -- 선택 정렬 수행 --");

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
			else
			{
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
			}
		}
	}
}

void ex007() {
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	selectionSort(list, size);
}