#pragma once
#include "base.h"
#define QUEUE_INIT_SIZE 10
#define QUEUEINCREMENT 10

typedef struct {
	QElemType* elem;
	int front;
	int rear;
	int stacksize;
}SqQueue;

Status INITQUEUE(SqQueue& Q);
Status QUEUEEMPTY(SqQueue Q);
int QUEUELENGTH(SqQueue Q);
Status GETHEAD(SqQueue Q, QElemType& item);
Status ENQUEUE(SqQueue& Q, QElemType item);
Status DEQUEUE(SqQueue& Q, QElemType& item);
Status PRINTQUEUE(SqQueue Q);