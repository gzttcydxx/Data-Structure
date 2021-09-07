#pragma once
#include "base.h"
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10

typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}SqStack;

Status INITSTACK(SqStack& S);
Status STACKEMPTY(SqStack& S);
int STACKLENGTH(SqStack S);
Status GETTOP(SqStack S, ElemType& item);
Status PUSH(SqStack& S, ElemType item);
Status POP(SqStack& S, ElemType& item);
Status PRINTSTACK(SqStack S);