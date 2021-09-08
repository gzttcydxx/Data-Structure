#pragma once
#include "base.h"
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status INITSTACK(SqStack& S);
Status STACKEMPTY(SqStack& S);
int STACKLENGTH(SqStack S);
Status GETTOP(SqStack S, SElemType& item);
Status PUSH(SqStack& S, SElemType item);
Status POP(SqStack& S, SElemType& item);
Status PRINTSTACK(SqStack S);