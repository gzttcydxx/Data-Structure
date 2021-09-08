#pragma once
#include "base.h"
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

inline Status compare(ElemType e1, ElemType e2);
Status INITLIST(SqList& L);
Status INSERTLIST(SqList& L, int i, ElemType item);
Status DELETELIST(SqList& L, int i, ElemType& item);
int LOCATEELEM(SqList L, ElemType item, Status(*compare)(ElemType, ElemType));
Status PRINTLIST(SqList L, Status(*visit)(ElemType));