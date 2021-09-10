#pragma once
#include "base.h"

template <typename QElemType> struct QNode {
	QElemType data;
	struct QNode<QElemType>* next;
};
template <typename QElemType> using QueuePtr = QNode<QElemType>*;
template <typename QElemType> struct LinkQueue {
	QueuePtr<QElemType> front;
	QueuePtr<QElemType> rear;
};

template <typename QElemType> Status INITQUEUE(LinkQueue<QElemType>& Q);
template <typename QElemType> Status QUEUEEMPTY(LinkQueue<QElemType> Q);
template <typename QElemType> int QUEUELENGTH(LinkQueue<QElemType> Q);
template <typename QElemType> Status GETHEAD(LinkQueue<QElemType> Q, QElemType& item);
template <typename QElemType> Status ENQUEUE(LinkQueue<QElemType>& Q, QElemType item);
template <typename QElemType> Status DEQUEUE(LinkQueue<QElemType>& Q, QElemType& item);
template <typename QElemType> Status PRINTQUEUE(LinkQueue<QElemType> Q);