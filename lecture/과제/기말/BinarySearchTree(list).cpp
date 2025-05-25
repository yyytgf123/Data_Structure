#include <stdio.h>
#include <stdlib.h>
		
typedef char element;
typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	
	while (p != NULL)
	{
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n 찾는 키가 없습니다!");
	return p;
}

treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode;
	// p가 없는 경우 node 생성하여 리턴
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	// x가 더 작은경우 왼쪽에 삽입
	else if (x < p->key)
	{
		p->left = insertNode(p->left, x);
	}
	// x가 더 큰 경우 오른쪽에 삽입
	else if (x > p->key)
	{
		p->right = insertNode(p->right, x);
	}
	else printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

void deleteNode(treeNode* root, element key) {
	treeNode* parent, *p, *succ, *succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	
	// 삭제할 노드의 위치 탐색
	// p가 null, key값을 찾으면 종료
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	// 삭제할 노드가 없는 경우
	if (p == NULL)
	{
		printf("\n 찾는 키가 이진트리에 없습니다.");
		return;
	}
	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL))
	{
		// parent가 NULL이 아니면, 즉 부모가 있는 경우
		if (parent != NULL)
		{
			// while문에서 찾은 p의 값이 부모의 왼쪽과 동일 시 left를 NULL
			if (parent->left == p)
			{
				parent->left = NULL;
			}
			// 아니면 오른쪽 값을 NULL
			else
			{
				parent->right = NULL;
			}
		}
		// 부모가 NULL이면 root 노드이니 root를 null
		else root = NULL;
	}
	// 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
		// 후보 초기화 과정
		succ_parent = p;
		succ = p->left;
		// 왼쪽에서 가장 큰 노드 찾기
		// 왼쪽 자식의 오른쪽 끝까지 내려감 -> 가장 큰 값
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		// succ이 succ_parent의 왼쪽 자식인지 오른쪽 자식인지 구분하여 포인터 조정
		// succ가 부모의 왼쪽 자식인 경우
		if (succ_parent->left == succ)
		{
			succ_parent->left = succ->left;
		}
		else
		{
			succ_parent->right = succ->left;
			p->key = succ->key;
			p = succ;
		}
	}
	free(p);
}

// 이진 탐색 트리를 중위 순회하면서 출력
void displayInorder(treeNode* root) {
	if (root)
	{
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}