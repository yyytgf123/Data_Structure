#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N 10

struct list_node {
	int vertex;
	int weight;
	struct list_node* link;
};

typedef struct list_node node;

typedef node* node_ptr;

node_ptr graph[N];

int visited[N];

void ex005() {
	int i;
	node_ptr temp;
	for (i = 0; i < 10; i++)
	{
		graph[i] = NULL;
		visited[i] = FALSE;
	}
}



