#pragma once
#include "base.h"

typedef int vertype;
typedef struct edge {
	int adjvex;
	int weight;
	struct edge* next;
}ELink;
typedef struct ver {
	vertype vertex;
	ELink* link;
}VLink;

void ADJLIST(VLink G[], int n);
void DFS(VLink G[], int visited[], int v);
void TRAVEL_DFS(VLink G[], int visited[], int n);
void BFS(VLink G[], int visited[], int v);
void TRAVEL_BFS(VLink G[], int visited[], int n);
