#include <stdio.h>
typedef int element;
int size11;

void bubbleSort(element a[], int size)
{
	int i, j, t;
	element temp;
	printf("\n정렬할 원소 : ");
	for (t = 0; t < size; t++)
	{
		printf("%d", a[t]);
	}
	for (i = size - 1; i > 0; i--)
	{
		printf("\n %d단계>>", size - i);
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