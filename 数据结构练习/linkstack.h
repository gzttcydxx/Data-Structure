#pragma once
#include "base.h"

typedef struct SNode {
	SElemType data;
	struct SNode* next;
}SNode, * LinkStack;

Status INITSTACK(LinkStack& S);
Status STACKEMPTY(LinkStack& S);
int STACKLENGTH(LinkStack S);
Status GETTOP(LinkStack S, SElemType& item);
Status PUSH(LinkStack& S, SElemType item);
Status POP(LinkStack& S, SElemType& item);
Status PRINTSTACK(LinkStack S);