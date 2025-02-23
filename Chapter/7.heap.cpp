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
		//heap tree의 각 level은 한 줄에 출력되도록 함
		if (pow(2, newLineIndex) == count)
		{
			printf("\n");
			newLineIndex++;
			count = 0; //새로운 줄 시작으로 초기화
		}
		count++;
	}
	printf("\n\n");
}

void insertData(Heap* heap, int data)
{
	int index;
	//heap 공간 확인
	if (heap->lastindex == MAX_NODES - 1)
	{
		printf("Heap is full\n");
		return;
	}

	//heap에 node를 확장시켜 데이터 추가
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
	//heap 존재 여부 검사
	if (heap->lastindex == 0)
	{
		printf("Heap is empty\n");
		return;
	}
	
	//root node에만 데이터가 존재하는 경우
	if (heap->lastindex == 1)
	{
		heap->nodes[heap->lastindex] = 0;
		heap->lastindex = 0;
		return;
	}

	//heap의 마지막 node의 데이터를 임시 변수에 저장
	temp = heap->nodes[heap->lastindex];
	heap->nodes[heap->lastindex] = 0;
	heap->lastindex --;

	parentindex = 1;
	childindex = 2;

	//root node부터 시작해서 자식 노드들의 데이터 값을 비교하여 업데이트
	while (childindex <= heap->lastindex)
	{
		//sibling node 중 가장 큰 node 선택
		if (heap->nodes[childindex] < heap->nodes[childindex + 1])
		{
			childindex += 1;
		}

		//임시 변수에 저장된 값과 비교
		if (temp > heap->nodes[childindex])
		{
			break;
		}
		
		//자식 node의 값이 더 클 경우 부모 node와 교체
		heap->nodes[parentindex] = heap->nodes[childindex];
		parentindex = childindex;
		childindex += 2;
	}
	heap->nodes[parentindex] = temp;
}