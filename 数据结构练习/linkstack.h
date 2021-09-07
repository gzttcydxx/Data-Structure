#pragma once
#include "base.h"

typedef struct SNode {
	ElemType data;
	struct SNode* next;
}SNode, * LinkStack;

Status INITSTACK(LinkStack& S);
Status STACKEMPTY(LinkStack& S);
int STACKLENGTH(LinkStack S);
Status GETTOP(LinkStack S, ElemType& item);
Status PUSH(LinkStack& S, ElemType item);
Status POP(LinkStack& S, ElemType& item);
Status PRINTSTACK(LinkStack S);