#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define VERTEX 7

typedef struct Node {
	int vertex;
	struct Node* link;
}Node;

Node* list[VERTEX];
int dfs_visited[VERTEX];

void Insert_edge(int mat[VERTEX][VERTEX], int start, int end)
{
	mat[start][end] = 1;
	mat[end][start] = 1;
}

void Mat2list(Node** list, int u, int v)
{
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node->vertex = v;
	node->link = list[u];
	list[u] = node;
}

void Graph_dfs_connected(Node** list, int v, int count)
{
	Node* w;
	dfs_visited[v] = count;
	printf("%3d  ", v);
	for (w = list[v]; w; w = w->link) {
		if (!dfs_visited[w->vertex])
			Graph_dfs_connected(list, w->vertex, count);
	}	
}

void Component_print(int count)
{
	printf("\n\n컴포넌트 개수: %d \n\n", count);

	for (int i = 1; i <= count; i++) {
		printf("컴포넌트 %d: ", i);
		for (int j = 0; j < VERTEX; j++)
			if (dfs_visited[j] == i) printf("%3d ", j);
		printf("\n");
	}
}

void Graph_connected(Node** list, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (dfs_visited[i] == 0) {
			count += 1;
			Graph_dfs_connected(list, i, count);
			printf("//");
		}
	}
	Component_print(count);
}

void main()
{
	int mat[VERTEX][VERTEX] = { 0 };

	Insert_edge(mat, 2, 3);
	Insert_edge(mat, 4, 5);
	Insert_edge(mat, 4, 6);
	Insert_edge(mat, 5, 6);

	for (int i = 0; i < VERTEX; i++) {
		for (int j = 0; j < VERTEX; j++) {
			if (mat[i][j] == 1) Mat2list(list, i, j);
		}
	}
	Graph_connected(list, VERTEX);	
}