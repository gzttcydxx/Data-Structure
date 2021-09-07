#include <stdio.h>
#include "sqqueue.h"

SqQueue CreateQueue() {
	SqQueue Q;
	const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
	INITQUEUE(Q);
	for (int i = 0; i < 9; i++) ENQUEUE(Q, M[i]);
	return Q;
}

int main() {
	int i = 0, j;
	SqQueue Q;
	ElemType e;
	const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
	INITQUEUE(Q);
	GETHEAD(Q, e);
	Q = CreateQueue();
	GETHEAD(Q, e);
	printf("%d\n\n", e);
	j = Q.front + 1;
	PRINTQUEUE(Q);
	return 0;
}