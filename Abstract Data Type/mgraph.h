#pragma once
#include "base.h"
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef struct MGraph {
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum;  // ¶¥µãÊý
	int arcnum;  // »¡Êý
};

Status CREATEGRAPH(MGraph& G);
void DFS(MGraph G, int visited[], int v);
Status TRAVEL_DFS(MGraph G);
Status TRAVEL_BFS(MGraph G);
Status MINSPANTREE_PRIM(MGraph G);