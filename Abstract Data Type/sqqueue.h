#pragma once
#include "base.h"
#define QUEUE_INIT_SIZE 10
#define QUEUEINCREMENT 10

template <typename QElemType> struct SqQueue {
	QElemType* elem;
	int front;
	int rear;
	int stacksize;
};

template <typename QElemType> Status INITQUEUE(SqQueue<QElemType>& Q);
template <typename QElemType> Status QUEUEEMPTY(SqQueue<QElemType> Q);
template <typename QElemType> int QUEUELENGTH(SqQueue<QElemType> Q);
template <typename QElemType> Status GETHEAD(SqQueue<QElemType> Q, QElemType& item);
template <typename QElemType> Status ENQUEUE(SqQueue<QElemType>& Q, QElemType item);
template <typename QElemType> Status DEQUEUE(SqQueue<QElemType>& Q, QElemType& item);
template <typename QElemType> Status PRINTQUEUE(SqQueue<QElemType> Q, Status(*visit)(QElemType));