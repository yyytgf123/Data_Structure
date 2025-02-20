#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 50
typedef struct Heap
{
	int nodes[MAX_NODES];
	int lastindex;
}Heap;

void initHeap(Heap* heap);
void insertData(Heap* heap, int data);
void printHeap(Heap heap);
void deleteData(Heap* heap);

int ex8()
{
	Heap heap;

	initHeap(&heap);

	insertData(&heap, 1);
	insertData(&heap, 3);
	insertData(&heap, 8);
	insertData(&heap, 13);
	insertData(&heap, 4);
	insertData(&heap, 10);
	insertData(&heap, 6);

	printHeap(heap);
	
	deleteData(&heap);
	printHeap(heap);

	deleteData(&heap);
	printHeap(heap);

	return 0;
}

void initHeap(Heap* heap)
{
	int i;
	for (i = 0; i < MAX_NODES; i++)
	{
		heap->nodes[i] = 0;
	}
	heap->lastindex = 0;
}

void printHeap(Heap heap)
{
	int i, count, newLineIndex;
	count = 1;
	newLineIndex = 0;
	for (i = 1; i <= heap.lastindex; i++)
	{
		printf("%d\t", heap.nodes[i]);
		//heap tree�� �� level�� �� �ٿ� ��µǵ��� ��
		if (pow(2, newLineIndex) == count)
		{
			printf("\n");
			newLineIndex++;
			count = 0; //���ο� �� �������� �ʱ�ȭ
		}
		count++;
	}
	printf("\n\n");
}

void insertData(Heap* heap, int data)
{
	int index;
	//heap ���� Ȯ��
	if (heap->lastindex == MAX_NODES - 1)
	{
		printf("Heap is full\n");
		return;
	}

	//heap�� node�� Ȯ����� ������ �߰�
	heap->lastindex++;
	index = heap->lastindex;

	while ((index != 1) && (data > heap->nodes[index / 2]))
	{
		heap->nodes[index] = heap->nodes[index / 2];
		index /= 2;
	}
	heap->nodes[index] = data;
}

void deleteData(Heap* heap)
{
	int temp, parentindex, childindex;
	//heap ���� ���� �˻�
	if (heap->lastindex == 0)
	{
		printf("Heap is empty\n");
		return;
	}
	
	//root node���� �����Ͱ� �����ϴ� ���
	if (heap->lastindex == 1)
	{
		heap->nodes[heap->lastindex] = 0;
		heap->lastindex = 0;
		return;
	}

	//heap�� ������ node�� �����͸� �ӽ� ������ ����
	temp = heap->nodes[heap->lastindex];
	heap->nodes[heap->lastindex] = 0;
	heap->lastindex --;

	parentindex = 1;
	childindex = 2;

	//root node���� �����ؼ� �ڽ� ������ ������ ���� ���Ͽ� ������Ʈ
	while (childindex <= heap->lastindex)
	{
		//sibling node �� ���� ū node ����
		if (heap->nodes[childindex] < heap->nodes[childindex + 1])
		{
			childindex += 1;
		}

		//�ӽ� ������ ����� ���� ��
		if (temp > heap->nodes[childindex])
		{
			break;
		}
		
		//�ڽ� node�� ���� �� Ŭ ��� �θ� node�� ��ü
		heap->nodes[parentindex] = heap->nodes[childindex];
		parentindex = childindex;
		childindex += 2;
	}
	heap->nodes[parentindex] = temp;
}