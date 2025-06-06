#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode {
	char data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void preorder(treeNode* root) {
	if (root)
	{
		// 루트 먼저 출력
		printf("%c", root->data);
		// 왼쪽 노드로 이동, 그러면 왼쪽 노드가 루트가 되어 출력
		preorder(root->left);
		// 다음 오른쪽 노드로 이동하여, 오른쪽 노드가 루트가 되어 출력
		preorder(root->right);
	}
}

void inorder(treeNode* root) {
	if (root)
	{
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root) {
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

void ex001() {
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("\n preoder : ");
	preorder(n1);
	
	printf("\n inorder : ");
	inorder(n1);

	printf("\n postorder : ");
	postorder(n1);
}
