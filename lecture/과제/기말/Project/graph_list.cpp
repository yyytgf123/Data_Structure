#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

//[인접 리스트]
//
//0: → 2 → 1
//1 : → 2
//2 : → 3
//3 : → NULL
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList_H[MAX_VERTEX];
} graphType;

void createGraph2(graphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++)
	{
		g->adjList_H[v] = NULL;
	}
}

//insertVertax(g, 4)
//[0] → NULL
//[1] → NULL
//[2] → NULL
//[3] → NULL
void insertVertax(graphType* g, int v) {
	if (((g->n)+1)>MAX_VERTEX)
	{
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

// 예시
// insertEdge2(g, 0, 2)
// [0] -> (2) -> NULL
// [1] -> NULL
// [2] -> NULL
// [3] -> NULL
// 
// insertEdge2(g, 0, 1)
// [0] -> (1) -> (2) -> NULL
// [1] -> NULL
// [2] -> NULL
// [3] -> NULL
void insertEdge2(graphType* g, int u, int v) {
	graphNode* node;

	if (u >= g->n || v >= g->n)
	{
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	// 동작
	// g->adjList_H[0] → (2) → (3) → NULL
	// g->adjList_H[0] → (1) → (2) → (3) → NULL
	// 기존 리스트 앞에 새 노드를 덧붙일 준비
	node->link = g->adjList_H[u];
	// 리스트의 시작점을 새 노드로 변경
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++)
	{
		printf("\n\t\t 정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p)
		{
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

void ex004() {
	int i;
	graphType* G1;
	G1 = (graphType*)malloc(sizeof(graphType));
	createGraph2(G1);

	for (i = 0; i < 4; i++)
	{
		insertVertax(G1, i);
	}
	insertEdge2(G1, 0, 3);
	insertEdge2(G1, 0, 1);
	insertEdge2(G1, 1, 3);
	insertEdge2(G1, 1, 2);
	insertEdge2(G1, 1, 0);
	insertEdge2(G1, 2, 3);
	insertEdge2(G1, 2, 1);
	insertEdge2(G1, 3, 2);
	insertEdge2(G1, 3, 0);
	print_adjList(G1);

}












