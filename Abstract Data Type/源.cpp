#include <stdio.h>
#include "mgraph.h"

int main() {
	MGraph G;
	CREATEGRAPH(G);
	TRAVEL_DFS(G);
	printf("\n");
	TRAVEL_BFS(G);
	return 0;
}