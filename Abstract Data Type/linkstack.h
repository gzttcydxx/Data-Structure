#pragma once
#include "base.h"

template <typename SElemType> struct SNode {
	SElemType data;
	struct SNode* next;
};
template <typename SElemType> using LinkStack = SNode<SElemType>*;

template <typename SElemType> Status INITSTACK(LinkStack<SElemType>& S);
template <typename SElemType> Status STACKEMPTY(LinkStack<SElemType>& S);
template <typename SElemType> int STACKLENGTH(LinkStack<SElemType> S);
template <typename SElemType> Status GETTOP(LinkStack<SElemType> S, SElemType& item);
template <typename SElemType> Status PUSH(LinkStack<SElemType>& S, SElemType item);
template <typename SElemType> Status POP(LinkStack<SElemType>& S, SElemType& item);
template <typename SElemType> Status PRINTSTACK(LinkStack<SElemType> S, Status(*visit)(SElemType));