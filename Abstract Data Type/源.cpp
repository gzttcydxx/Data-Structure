#include <stdio.h>
#include "mgraph.h"

int main() {
	MGraph G;
	CREATEGRAPH(G);
	MINSPANTREE_PRIM(G);
	return 0;
}