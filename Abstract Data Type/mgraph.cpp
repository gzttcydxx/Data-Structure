#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

Status CREATEGRAPH(MGraph& G) {
	int vn, en, i, j, weight;
	FILE* fp = fopen("graph.in", "r");
	fscanf(fp, "%d", &vn);
	G.vexnum = vn;
	fscanf(fp, "%d", &en);
	G.arcnum = en;
	for (i = 0; i < vn; i++) for (j = 0; j < vn; j++) G.arcs[i][j] = INFINITY;
	for (int k = 0; k < en; k++) {
		fscanf(fp, "%d %d %d", &i, &j, &weight);
		G.arcs[i - 1][j - 1] = weight;
		G.arcs[j - 1][i - 1] = weight;
	}
	return OK;
}

void DFS(MGraph G, int visited[], int v) {
	printf("%d ", v + 1);
	visited[v] = 1;
	for (int i = v + 1; i < G.vexnum; i++) if (!visited[i] && G.arcs[v][i] < INFINITY) DFS(G, visited, i);
}

Status TRAVEL_DFS(MGraph G) {
	int* visited;
	visited = (int*)calloc(G.vexnum, sizeof(int));
	if (!visited) exit(OVERFLOW);
	for (int i = 0; i < G.vexnum; i++) if (visited[i] == 0) DFS(G, visited, i);
	return OK;
}

Status TRAVEL_BFS(MGraph G) {
	int* visited;
	visited = (int*)calloc(G.vexnum, sizeof(int));
	if (!visited) exit(OVERFLOW);
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			printf("%d ", i + 1);
			visited[i] = 1;
		}
		for (int j = i + 1; j < G.vexnum; j++) if (!visited[j] && G.arcs[i][j] != INFINITY) {
			printf("%d ", j + 1);
			visited[j] = 1;
		}
	}
	return OK;
}