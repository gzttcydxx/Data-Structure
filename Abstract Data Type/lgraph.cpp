#include <stdio.h>
#include <stdlib.h>
#include "lgraph.h"
#include "linkstack.cpp"
#include "linkqueue.cpp"

template <typename VElemType> Status INITGRAPH(LGraph<VElemType>& G, int n) {
	G.num = n;
	G.vertexes = (VLink<VElemType>*)malloc(G.num * sizeof(VLink<VElemType>));
	if (!G.vertexes) exit(OVERFLOW);
	return OK;
}

template <typename VElemType> Status CREATEGRAPH(LGraph<VElemType>& G) {
	int vi, vj, weight, n, e;
	ELink* p, * q;
	FILE* fp = fopen("graph.in", "r");
	fscanf(fp, "%d", &n);
	G.num = n;
	G.vertexes = (VLink<VElemType>*)malloc(n * sizeof(VLink<VElemType>));
	if (!G.vertexes) exit(OVERFLOW);
	for (int i = 0; i < n; i++) {
		G.vertexes[i].vertex = i + 1;
		G.vertexes[i].link = NULL;
	}
	fscanf(fp, "%d", &e);
	for (int i = 0; i < e; i++) {
		fscanf(fp, "%d %d %d", &vi, &vj, &weight);
		p = (ELink*)malloc(sizeof(ELink));
		if (!p) exit(OVERFLOW);
		p->adjvex = vj - 1;
		p->weight = weight;
		p->next = NULL;
		if (!G.vertexes[vi - 1].link) G.vertexes[vi - 1].link = p;
		else {
			q = G.vertexes[vi - 1].link;
			while (q->next) q = q->next;
			q->next = p;
		}
	}
	fclose(fp);
	return OK;
}

template <typename VElemType> void DFS(LGraph<VElemType> G, int visited[], int v) {
	/*µÝ¹éÊµÏÖ
	int w;
	ELink* p;
	printf("%d ", v + 1);
	visited[v] = 1;
	p = G.vertexes[v].link;
	while (p) {
		if (!visited[p->adjvex]) DFS(G, visited, p->adjvex);
		p = p->next;
	}
	*/
	int w;
	ELink* p;
	LinkStack<int> S;
	INITSTACK(S);
	PUSH(S, v);
	printf("%d ", v + 1);
	visited[v] = 1;
	while (!STACKEMPTY(S)) {
		GETTOP(S, w);
		p = G.vertexes[w].link;
		while (p) {
			if (!visited[p->adjvex]) {
				printf("%d ", p->adjvex + 1);
				visited[p->adjvex] = 1;
				PUSH(S, p->adjvex);
				break;
			}
			p = p->next;
		}
		if (!p) POP(S, w);
	}
}

template <typename VElemType> Status TRAVEL_DFS(LGraph<VElemType> G) {
	int* visited;
	visited = (int*)calloc(G.num, sizeof(int));
	if (!visited) exit(OVERFLOW);
	for (int i = 0; i < G.num; i++) if (visited[i] == 0) DFS(G, visited, i);
	return OK;
}

template <typename VElemType> void BFS(LGraph<VElemType> G, int visited[], int v) {
	int w;
	ELink* p;
	LinkQueue<int> Q;
	INITQUEUE(Q);
	ENQUEUE(Q, v);
	while (!QUEUEEMPTY(Q)) {
		DEQUEUE(Q, w);
		if (!visited[w]) {
			printf("%d ", w + 1);
			visited[w] = 1;
			p = G.vertexes[w].link;
			while (p) {
				ENQUEUE(Q, p->adjvex);
				p = p->next;
			}
		}
	}
}

template <typename VElemType> Status TRAVEL_BFS(LGraph<VElemType> G) {
	int* visited;
	visited = (int*)calloc(G.num, sizeof(int));
	if (!visited) exit(OVERFLOW);
	for (int i = 0; i < G.num; i++) if (visited[i] == 0) BFS(G, visited, i);
	return OK;
}

template <typename VElemType> Status MINSPANTREE_PRIM(LGraph<VElemType> G) {
	ELink* p;
	int* lowcost = (int*)calloc(G.num, sizeof(int)), * teend = (int*)calloc(G.num, sizeof(int)), mincost, index;
	if (!lowcost || !teend) exit(OVERFLOW);
	for (int i = 1; i < G.num; i++) lowcost[i] = INT_MAX;
	p = G.vertexes[0].link;
	while (p) {
		lowcost[p->adjvex] = p->weight;
		p = p->next;
	}
	for (int i = 1; i < G.num; i++) {
		mincost = INT_MAX;
		for (int j = 1; j < G.num; j++) if (lowcost[j] > 0 && mincost > lowcost[j]) {
			mincost = lowcost[j];
			index = j;
		}
		printf("(%d, %d)\n", teend[index] + 1, index + 1);
		lowcost[index] = 0;
		p = G.vertexes[index].link;
		while (p) {
			if (p->weight < lowcost[p->adjvex]) {
				lowcost[p->adjvex] = p->weight;
				teend[p->adjvex] = index;
			}
			p = p->next;
		}
	}
	return OK;
}