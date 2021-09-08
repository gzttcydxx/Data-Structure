#pragma once
#include "base.h"

typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status INITQUEUE(LinkQueue& Q);
Status QUEUEEMPTY(LinkQueue Q);
int QUEUELENGTH(LinkQueue Q);
Status GETHEAD(LinkQueue Q, QElemType& item);
Status ENQUEUE(LinkQueue& Q, QElemType item);
Status DEQUEUE(LinkQueue& Q, QElemType& item);
Status PRINTQUEUE(LinkQueue Q);