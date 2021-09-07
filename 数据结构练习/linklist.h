#pragma once
#include "base.h"

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

inline Status compare(ElemType e1, ElemType e2);
Status INITLINKLIST(LinkList& L);
Status INSERTLINKLIST(LinkList& L, int i, ElemType item);
Status DELETELINKLIST(LinkList& L, int i, ElemType& item);
int LOCATEELEM(LinkList L, ElemType item, Status(*compare)(ElemType, ElemType));
Status GETELEM(LinkList L, int i, ElemType& item);
Status PRINTLINKLIST(LinkList L);