#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// 가중치 없는 유향 그래프
typedef struct grapeType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

void createGraph(graphType* g) {
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++)
		for (j = 0; j < MAX_VERTEX; j++)
			g->adjMatrix[i][j] = 0;
}

void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX)
	{
		printf("\n 그래프 정점의 개수를 초과했습니다.");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v) {
	if (u >= g->n || v >= g->n)
	{
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	g->adjMatrix[u][v] = 1;
}

void print_adjMatrix(grapeType* g) {
	int i, j;
	for (i = 0; i < (g->n); i++) {
		printf("\n\t\t");
		for (j = 0; j < (g->n); j++)
			printf("%2d", g->adjMatrix[i][j]);
	}
}

void ex1() {
	int i;
	grapeType* G1;
	G1 = (grapeType*)malloc(sizeof(graphType));

	createGraph(G1);

	for (i = 0; i < 3; i++)
		insertVertex(G1, i);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 0, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 1, 2);
	printf("\n\n G4");
	print_adjMatrix(G1);

	getchar();
}