#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

Status INITSTACK(SqStack& S) {
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status STACKEMPTY(SqStack& S) {
	return S.base == S.top;
}

int STACKLENGTH(SqStack S) {
	return S.top - S.base;
}

Status GETTOP(SqStack S, ElemType& item) {
	if (STACKEMPTY(S)) return ERROR;
	item = *(S.top - 1);
	return OK;
}

Status PUSH(SqStack& S, ElemType item) {
	ElemType* newbase;
	if (STACKLENGTH(S) >= S.stacksize) {
		newbase = (ElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = item;
	return OK;
}

Status POP(SqStack& S, ElemType& item) {
	if (STACKEMPTY(S)) return ERROR;
	item = *--S.top;
	return OK;
}

Status PRINTSTACK(SqStack S, Status(*visit)(ElemType)) {
	ElemType* p = S.base;
	while (p != S.top) (*visit)(*p++);
	return OK;
}