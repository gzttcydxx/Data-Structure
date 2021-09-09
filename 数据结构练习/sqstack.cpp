#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

template <typename SElemType> Status INITSTACK(SqStack<SElemType>& S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

template <typename SElemType> Status STACKEMPTY(SqStack<SElemType>& S) {
	return S.base == S.top;
}

template <typename SElemType> int STACKLENGTH(SqStack<SElemType> S) {
	return S.top - S.base;
}

template <typename SElemType> Status GETTOP(SqStack<SElemType> S, SElemType& item) {
	if (STACKEMPTY(S)) return ERROR;
	item = *(S.top - 1);
	return OK;
}

template <typename SElemType> Status PUSH(SqStack<SElemType>& S, SElemType item) {
	SElemType* newbase;
	if (STACKLENGTH(S) >= S.stacksize) {
		newbase = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!newbase) exit(OVERFLOW);
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = item;
	return OK;
}

template <typename SElemType> Status POP(SqStack<SElemType>& S, SElemType& item) {
	if (STACKEMPTY(S)) return ERROR;
	item = *--S.top;
	return OK;
}

template <typename SElemType> Status PRINTSTACK(SqStack<SElemType> S, Status(*visit)(SElemType)) {
	SElemType* p = S.base;
	while (p != S.top) visit(*p++);
	return OK;
}