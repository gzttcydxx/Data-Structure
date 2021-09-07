#pragma once
#include "base.h"

typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status INITQUEUE(LinkQueue& Q);
Status QUEUEEMPTY(LinkQueue Q);
int QUEUELENGTH(LinkQueue Q);
Status GETHEAD(LinkQueue Q, ElemType& item);
Status ENQUEUE(LinkQueue& Q, ElemType item);
Status DEQUEUE(LinkQueue& Q, ElemType& item);
Status PRINTQUEUE(LinkQueue Q);