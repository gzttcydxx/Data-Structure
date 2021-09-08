#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

Status INITLIST(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status INSERTLIST(SqList& L, int i, ElemType item) {
	ElemType* newbase, * q;
	if (i < 1 || i > L.length + 1) return ERROR;
	if (L.length >= L.listsize) {
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);
	for (ElemType* p = &(L.elem[L.length - 1]); p >= q; p--) * (p + 1) = *p;
	*q = item;
	L.length++;
	return OK;
}

Status DELETELIST(SqList& L, int i, ElemType &item) {
	ElemType* p,* q;
	if ((i < 1) || (i > L.length)) return ERROR;
	p = &(L.elem[i - 1]);
	item = *p;
	for (p++, q = L.elem + L.length - 1; p <= q; p++) * (p - 1) = *p;
	L.length--;
	return OK;
}

int LOCATEELEM(SqList L, ElemType item) {
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && !compare(*p++, item)) i++;
	if (i <= L.length) return i;
	else return ERROR;
}

Status PRINTLIST(SqList L) {
	for (int i = 0; i < L.length; i++) visit(L.elem[i]);
	return OK;
}