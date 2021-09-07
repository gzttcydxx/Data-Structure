#include <stdio.h>
#include <malloc.h>
#include "graph.h"

void ADJLIST(VLink G[], int n) {
	int vi, vj, weight, e;
	ELink* p, * q;
	FILE* fp = fopen("graph.in", "r");
	for (int i = 0; i < n; i++) {
		G[i].vertex = i + 1;
		G[i].link = NULL;
	}
	fscanf(fp, "%d", &e);
	for (int i = 0; i < e; i++) {
		fscanf(fp, "%d %d %d", &vi, &vj, &weight);
		p = (ELink*)malloc(sizeof(ELink));
		p->adjvex = vj - 1;
		p->weight = weight;
		p->next = NULL;
		if (!G[vi - 1].link) G[vi - 1].link = p;
		else {
			q = G[vi - 1].link;
			while (q->next) q = q->next;
			q->next = p;
		}
	}
	fclose(fp);
}

void DFS(VLink G[], int visited[], int v) {
	int w;
	ELink* p;
	printf("%d ", v + 1);
	visited[v] = 1;
	p = G[v].link;
	while (p) {
		if (visited[p->adjvex] == 0) DFS(G, visited, p->adjvex);
		p = p->next;
	}
}

void TRAVEL_DFS(VLink G[], int visited[], int n) {
	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++) if (visited[i] == 0) DFS(G, visited, i);
}

void BFS(VLink G[], int visited[], int v) {
	int w;
	ELink* p;
	printf("%d ", v + 1);
	visited[v] = 1;
}

void TRAVEL_BFS(VLink G[], int visited[], int n) {
	return;
}