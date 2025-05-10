#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define NOT_EXIST -1

// �迭 ���·� ����
int bst[MAX_NODES];

// �ʱ�ȭ
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
	// nodeInex���� -1��, �� ���� ������ return 0�� ��ȯ
	// �� ���� ���� �迭���� �� �̵�
	return (nodeIndex < MAX_NODES && bst[nodeIndex] != NOT_EXIST);
}

int insertNode(int key) {
	int curNodeIndex = 0; // rootNode�� �ε���

	while (hasEntry(curNodeIndex)) {
		// ���� bst �ε����� ������ key�� �� ũ�� ������, ������ ����
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

int deleteNode(int key) {

}

int printInorder() {

}

int main()
{
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
