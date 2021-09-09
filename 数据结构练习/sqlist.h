#pragma once
#include "base.h"
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

template <typename ElemType> struct SqList {
	ElemType* elem;
	int length;
	int listsize;
};

template <typename ElemType> Status INITLIST(SqList<ElemType>& L);
template <typename ElemType> Status INSERTLIST(SqList<ElemType>& L, int i, ElemType item);
template <typename ElemType> Status DELETELIST(SqList<ElemType>& L, int i, ElemType& item);
template <typename ElemType> int LOCATEELEM(SqList<ElemType> L, ElemType item, Status(*compare)(ElemType, ElemType));
template <typename ElemType> Status PRINTLIST(SqList<ElemType> L, Status(*visit)(ElemType));