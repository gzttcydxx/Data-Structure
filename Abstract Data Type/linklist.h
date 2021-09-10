#pragma once
#include "base.h"

template <typename ElemType> struct LNode {
	ElemType data;
	struct LNode* next;
};
template <typename ElemType> using LinkList = LNode<ElemType>*;

template <typename ElemType> Status INITLINKLIST(LinkList<ElemType>& L);
template <typename ElemType> Status INSERTLINKLIST(LinkList<ElemType>& L, int i, ElemType item);
template <typename ElemType> Status DELETELINKLIST(LinkList<ElemType>& L, int i, ElemType& item);
template <typename ElemType> int LOCATEELEM(LinkList<ElemType> L, ElemType item, Status(*compare)(ElemType, ElemType));
template <typename ElemType> Status GETELEM(LinkList<ElemType> L, int i, ElemType& item);
template <typename ElemType> Status PRINTLINKLIST(LinkList<ElemType> L, Status(*visit)(ElemType));