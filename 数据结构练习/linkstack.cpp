#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

template <typename SElemType> Status INITSTACK(LinkStack<SElemType>& S) {
	S = (LinkStack<SElemType>)malloc(sizeof(SNode<SElemType>));
	if (!S) exit(OVERFLOW);
	S->next = NULL;
	return OK;
}

template <typename SElemType> Status STACKEMPTY(LinkStack<SElemType>& S) {
	if (!S->next) return TRUE;
	else return FALSE;
}

template <typename SElemType> int STACKLENGTH(LinkStack<SElemType> S) {
	int i = 0;
	LinkStack<SElemType> p = S->next;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}

template <typename SElemType> Status GETTOP(LinkStack<SElemType> S, SElemType& item) {
	if (STACKEMPTY(S)) return ERROR;
	item = S->next->data;
	return OK;
}

template <typename SElemType> Status PUSH(LinkStack<SElemType>& S, SElemType item) {
	LinkStack<SElemType> p = (LinkStack<SElemType>)malloc(sizeof(SNode<SElemType>));
	if (!p) exit(OVERFLOW);
	p->data = item;
	p->next = S->next;
	S->next = p;
	return OK;
}

template <typename SElemType> Status POP(LinkStack<SElemType>& S, SElemType& item) {
	LinkStack<SElemType> p;
	if (STACKEMPTY(S)) return ERROR;
	item = S->next->data;
	p = S->next;
	S->next = p->next;
	free(p);
	return OK;
}

template <typename SElemType> Status PRINTSTACK(LinkStack<SElemType> S, Status(*visit)(SElemType)) {
	LinkStack<SElemType> p = S->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	return OK;
}