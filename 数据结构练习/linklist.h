#pragma once
#include "base.h"

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

Status INITLINKLIST(LinkList& L);
Status INSERTLINKLIST(LinkList& L, int i, ElemType item);
Status DELETELINKLIST(LinkList& L, int i, ElemType& item);
int LOCATEELEM(LinkList L, ElemType item);
Status GETELEM(LinkList L, int i, ElemType& item);
Status PRINTLINKLIST(LinkList L);