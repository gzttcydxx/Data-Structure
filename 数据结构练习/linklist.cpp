#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

Status INITLINKLIST(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	L->next = NULL;
	return OK;
}

Status INSERTLINKLIST(LinkList& L, int i, ElemType item) {
	int j = 0;
	LinkList p = L, q;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	q = (LinkList)malloc(sizeof(LNode));
	if (!q) exit(OVERFLOW);
	q->data = item;
	q->next = p->next;
	p->next = q;
	return OK;
}

Status DELETELINKLIST(LinkList& L, int i, ElemType& item) {
	int j = 0;
	LinkList p = L, q;
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

int LOCATEELEM(LinkList L, ElemType item) {
	int i = 1;
	LinkList p = L->next;
	while (p && !compare(p->data, item)) {
		p = p->next;
		i++;
	}
	if (!p) return ERROR;
	else return i;
}

Status GETELEM(LinkList L, int i, ElemType& item) {
	int j = 0;
	LinkList p = L;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	item = p->data;
	return OK;
}

Status PRINTLINKLIST(LinkList L) {
	LinkList p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	return OK;
}