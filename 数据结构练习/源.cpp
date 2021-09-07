#include <stdio.h>
#include "sqstack.h"

SqStack CreateStack() {
	SqStack S;
	const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
	INITSTACK(S);
	for (int i = 8; i >= 0; i--) PUSH(S, M[i]);
	return S;
}

int main() {
	int i = 0;
	SqStack S = CreateStack();
	ElemType* p;
	PUSH(S, 1);
	PUSH(S, 2);
	PUSH(S, 3);
	PUSH(S, 4);
	PUSH(S, 5);
	PRINTSTACK(S);
	return 0;
}