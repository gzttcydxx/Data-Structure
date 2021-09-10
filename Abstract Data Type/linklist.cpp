#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

template <typename ElemType> Status INITLINKLIST(LinkList<ElemType>& L) {
	L = (LinkList<ElemType>)malloc(sizeof(LNode<ElemType>));
	if (!L) exit(OVERFLOW);
	L->next = NULL;
	return OK;
}

template <typename ElemType> Status INSERTLINKLIST(LinkList<ElemType>& L, int i, ElemType item) {
	int j = 0;
	LinkList<ElemType> p = L, q;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	q = (LinkList<ElemType>)malloc(sizeof(LNode<ElemType>));
	if (!q) exit(OVERFLOW);
	q->data = item;
	q->next = p->next;
	p->next = q;
	return OK;
}

template <typename ElemType> Status DELETELINKLIST(LinkList<ElemType>& L, int i, ElemType& item) {
	int j = 0;
	LinkList<ElemType> p = L, q;
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) return ERROR;
	q = p->next;
	p->next = p->next->next;
	item = q->data;
	free(q);
	return OK;
}

template <typename ElemType> int LOCATEELEM(LinkList<ElemType> L, ElemType item, Status(*compare)(ElemType, ElemType)) {
	int i = 1;
	LinkList<ElemType> p = L->next;
	while (p && !compare(p->data, item)) {
		p = p->next;
		i++;
	}
	if (!p) return ERROR;
	else return i;
}

template <typename ElemType> Status GETELEM(LinkList<ElemType> L, int i, ElemType& item) {
	int j = 0;
	LinkList<ElemType> p = L;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	item = p->data;
	return OK;
}

template <typename ElemType> Status PRINTLINKLIST(LinkList<ElemType> L, Status(*visit)(ElemType)) {
	LinkList<ElemType> p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	return OK;
}