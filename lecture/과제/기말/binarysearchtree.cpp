#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define NOT_EXIST -1

// 배열 형태로 구현
int bst[MAX_NODES];

// 초기화
void initBST() {
	for (int i = 0; i < MAX_NODES; i++) {
		bst[i] = NOT_EXIST;
	}
}

/// <summary>
/// root => 0
/// root->left => 1
/// root->right => 2
/// root->left->left => 3
/// root->left->right => 4
/// root->right->left => 5
/// root->right->right => 6
/// </summary>
int leftChild(int nodeIndex) {
	return nodeIndex * 2 + 1;
}

int rightChild(int nodeIndex) {
	return nodeIndex * 2 + 2;
}
// ----------------------------//

int hasEntry(int nodeIndex) {
	// nodeInex값이 -1로, 즉 값이 없으면 return 0을 반환
	// 즉 값이 없는 배열까지 쭉 이동
	return (nodeIndex < MAX_NODES && bst[nodeIndex] != NOT_EXIST);
}

void insertNode(int key) {
	int curNodeIndex = 0; // rootNode의 인덱스

	while (hasEntry(curNodeIndex)) {
		// 현재 bst 인덱스의 값보다 key가 더 크면 오른쪽, 작으면 왼쪽
		if (key < bst[curNodeIndex])
		{
			curNodeIndex = leftChild(curNodeIndex);
		}
		else
		{
			curNodeIndex = rightChild(curNodeIndex);
		}
	}

	bst[curNodeIndex] = key;
}

void deleteNodeByIndex(int nodeIndex) {
	int leftChildIndex = leftChild(nodeIndex);
	int rightChildIndex = rightChild(nodeIndex);

	if (!hasEntry(leftChildIndex) && !hasEntry(rightChildIndex))
	{
		bst[nodeIndex] = NOT_EXIST;
	}
	else if (hasEntry(leftChildIndex) && !hasEntry(rightChildIndex))
	{
		bst[nodeIndex] = bst[leftChildIndex];
		deleteNodeByIndex(leftChildIndex);
	}
	else if (!hasEntry(leftChildIndex) && hasEntry(rightChildIndex))
	{
		bst[nodeIndex] = bst[rightChildIndex];
		deleteNodeByIndex(rightChildIndex);
	}
	else
	{
		int successorIndex = rightChildIndex;
		while (hasEntry(leftChild(successorIndex)))
		{
			successorIndex = leftChild(successorIndex);
		}
		bst[nodeIndex] = bst[successorIndex];
		deleteNodeByIndex(successorIndex);
	}
}

// 인덱스로 삭제
// key로 찾은 뒤 재귀함수로 자식 노드로 가져옴
void deleteNode(int key) {
	int curNodeIndex = 0;

	while (hasEntry(curNodeIndex)) {
		if (key < bst[curNodeIndex])
		{
			curNodeIndex = leftChild(curNodeIndex);
		}
		else if (key > bst[curNodeIndex])
		{
			curNodeIndex = rightChild(curNodeIndex);
		}
		else if (key == bst[curNodeIndex]) break;
	}
	deleteNodeByIndex(curNodeIndex);
}

void inorder(int nodeIndex) {
	if (!hasEntry(nodeIndex)) return;

	inorder(leftChild(nodeIndex));
	printf("%d@%d ", bst[nodeIndex], nodeIndex);
	inorder(rightChild(nodeIndex));
}

void printInorder() {
	inorder(0);
	printf("\n\n");
}

int main()
{
	initBST();

	insertNode(5);
	insertNode(2);
	insertNode(3);
	insertNode(1);
	insertNode(8);
	insertNode(10);
	insertNode(9);
	insertNode(6);

	printInorder();
	printf("\n");

	deleteNode(2);

	printInorder();
	printf("\n");

	deleteNode(5);

	printInorder();
	printf("\n");
}