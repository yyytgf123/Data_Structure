#include <stdio.h>

typedef int element;
int size2;

void bubblesort(element a[], int size) {
	int i, j, t;
	element temp;
	printf("\n ������ ���� : ");
	for (t = 0; t < size; t++)
	{
		printf("%d ", a[t]);
	}
	printf("\n -- ���� ���� ���� -- ");
	// �� �� ���ۿ� ���� ū ���� �� �ڿ� ������ �� �ڴ� ���ص���
	// �׷��� size - 1�� i--�� ���� ���������� �˻� ���ϴ� ����
	for (i = size - 1; i > 0; i--)
	{
		printf("\n %d�ܰ�--", size - i);
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