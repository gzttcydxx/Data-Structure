#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

Status INITSTACK(LinkStack& S) {
	S = (LinkStack)malloc(sizeof(struct SNode));
	if (!S) exit(OVERFLOW);
	S->next = NULL;
	return OK;
}

Status STACKEMPTY(LinkStack& S) {
	if (!S->next) return TRUE;
	else return FALSE;
}

int STACKLENGTH(LinkStack S) {
	int i = 0;
	LinkStack p = S->next;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}

Status GETTOP(LinkStack S, ElemType& item) {
	if (STACKEMPTY(S)) return ERROR;
	item = S->next->data;
	return OK;
}

Status PUSH(LinkStack& S, ElemType item) {
	LinkStack p = (LinkStack)malloc(sizeof(struct SNode));
	if (!p) exit(OVERFLOW);
	p->data = item;
	p->next = S->next;
	S->next = p;
	return OK;
}

Status POP(LinkStack& S, ElemType& item) {
	LinkStack p;
	if (STACKEMPTY(S)) return ERROR;
	item = S->next->data;
	p = S->next;
	S->next = p->next;
	free(p);
	return OK;
}

Status PRINTSTACK(LinkStack S, Status(*visit)(ElemType)) {
	LinkStack p = S->next;
	while (p) {
		(*visit)(p->data);
		p = p->next;
	}
	return OK;
}