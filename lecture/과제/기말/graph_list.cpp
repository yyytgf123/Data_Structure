#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList_H[MAX_VERTEX];
} graphType;

void createGraph(graphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL;
}

static void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX)
	{
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v) {
	graphNode* node;

	if (u >= g->n || v >= g->n)
	{
		printf("\n �׷����� ���� �����Դϴ�!");
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t ���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p) {
			// ���ĺ� �ҹ��ڷ� ���, 65 = A;
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

void ex2() {
	int i;
	graphType* G1;
	G1 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1);

	for (i = 0; i < 4; i++)
		insertVertex(G1, i);
	insertEdge(G1,0,3);
	insertEdge(G1,0,1);
	insertEdge(G1,1,3);
	insertEdge(G1,1,2);
	insertEdge(G1,1,0);
	insertEdge(G1,2,3);
	insertEdge(G1,2,1);
	insertEdge(G1,3,2);
	insertEdge(G1,3,1);
	insertEdge(G1,3,0);
	printf("\n G1�� ���� ����Ʈ");
	print_adjList(G1);
}