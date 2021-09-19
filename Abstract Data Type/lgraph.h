#pragma once
#include "base.h"

typedef struct edge {
	int adjvex;
	int weight;
	struct edge* next;
}ELink;
template <typename VElemType> struct VLink {
	VElemType vertex;
	ELink* link;
};
template <typename VElemType> struct LGraph {
	VLink<VElemType>* vertexes;
	int num;
};

template <typename VElemType> Status CREATEGRAPH(LGraph<VElemType>& G);
template <typename VElemType> void DFS(LGraph<VElemType> G, int visited[], int v);
template <typename VElemType> Status TRAVEL_DFS(LGraph<VElemType> G);
template <typename VElemType> void BFS(LGraph<VElemType> G, int visited[], int v);
template <typename VElemType> Status TRAVEL_BFS(LGraph<VElemType> G);
