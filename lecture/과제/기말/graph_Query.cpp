#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

typedef struct graphType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

void createGraph(graphType* g) {
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++)
	{
		for (j = 0; j < MAX_VERTEX; j++)
		{
			g->adjMatrix[i][j] = 0;
		}
	}
}

void insertVertex2(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX)
	{
		printf("\n 그래프의 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

void insertEdge2(graphType* g, int u, int v) {
	if (u >= g->n || v >= g->n)
	{
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	g->adjMatrix[u][v] = 1;
}

void print_adjMatrix(graphType* g) {
	int i, j;
	for (i = 0; i < (g->n); i++)
	{
		printf("\n\t\t");
		for (j = 0; j < (g->n); j++)
		{
			printf("%2d", g->adjMatrix[i][j]);
		}
	}
}

void ex003() {
	int i;
	graphType* G1;
	G1 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1);

	for (i = 0; i < 4; i++)
	{
		insertVertex2(G1, i);
	}
	insertEdge2(G1, 0, 1);
	insertEdge2(G1, 0, 3);
	insertEdge2(G1, 1, 0);
	insertEdge2(G1, 1, 2);
	insertEdge2(G1, 1, 3);
	insertEdge2(G1, 2, 3);
	insertEdge2(G1, 3, 0);
	insertEdge2(G1, 3, 1);
	insertEdge2(G1, 3, 2);
	printf("\n G1의 인접 행렬");
	print_adjMatrix(G1);
}