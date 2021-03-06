#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

template <typename ElemType> Status INITLIST(SqList<ElemType>& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

template <typename ElemType> Status INSERTLIST(SqList<ElemType>& L, int i, ElemType item) {
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

template <typename ElemType> Status DELETELIST(SqList<ElemType>& L, int i, ElemType &item) {
	ElemType* p,* q;
	if ((i < 1) || (i > L.length)) return ERROR;
	p = &(L.elem[i - 1]);
	item = *p;
	for (p++, q = L.elem + L.length - 1; p <= q; p++) * (p - 1) = *p;
	L.length--;
	return OK;
}

template <typename ElemType> int LOCATEELEM(SqList<ElemType> L, ElemType item, Status(*compare)(ElemType, ElemType)) {
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && !compare(*p++, item)) i++;
	if (i <= L.length) return i;
	else return ERROR;
}

template <typename ElemType> Status PRINTLIST(SqList<ElemType> L, Status(*visit)(ElemType)) {
	for (int i = 0; i < L.length; i++) visit(L.elem[i]);
	return OK;
}