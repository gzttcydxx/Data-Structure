#pragma once
#include "base.h"
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10

template <typename SElemType> struct SqStack {
	SElemType* base;
	SElemType* top;
	int stacksize;
};

template <typename SElemType> Status INITSTACK(SqStack<SElemType>& S);
template <typename SElemType> Status STACKEMPTY(SqStack<SElemType>& S);
template <typename SElemType> int STACKLENGTH(SqStack<SElemType> S);
template <typename SElemType> Status GETTOP(SqStack<SElemType> S, SElemType& item);
template <typename SElemType> Status PUSH(SqStack<SElemType>& S, SElemType item);
template <typename SElemType> Status POP(SqStack<SElemType>& S, SElemType& item);
template <typename SElemType> Status PRINTSTACK(SqStack<SElemType> S, Status(*visit)(SElemType));