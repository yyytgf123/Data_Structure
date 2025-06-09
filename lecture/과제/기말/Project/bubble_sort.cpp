#include <stdio.h>

typedef int element;
int size2;

void bubblesort(element a[], int size) {
	int i, j, t;
	element temp;
	printf("\n 정렬할 원소 : ");
	for (t = 0; t < size; t++)
	{
		printf("%d ", a[t]);
	}
	printf("\n -- 버블 정렬 수행 -- ");
	// 한 번 동작에 가장 큰 값이 맨 뒤에 놓여서 맨 뒤는 안해도됌
	// 그래서 size - 1로 i--를 통해 마지막꺼는 검사 안하는 구조
	for (i = size - 1; i > 0; i--)
	{
		printf("\n %d단계--", size - i);
		for (j = 1; j <= i; j++)
		{
			if (a[j - 1] > a[j])
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
			printf("\n\t");
			for (t = 0; t < size; t++)
			{
				printf("%3d", a[t]);
			}
		}
	}
}

void ex008()
{
	element list[8] = { 69,10,30,2,16,8,31,22 };
	size2 = 8;
	bubblesort(list,size2);
}