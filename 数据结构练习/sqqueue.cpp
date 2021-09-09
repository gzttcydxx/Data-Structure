#include <stdio.h>
#include <stdlib.h>
#include "sqqueue.h"

template <typename QElemType> Status INITQUEUE(SqQueue<QElemType>& Q) {
	Q.elem = (QElemType*)malloc(QUEUE_INIT_SIZE * sizeof(QElemType));
	if (!Q.elem) exit(OVERFLOW);
	Q.front = -1;
	Q.rear = -1;
	return OK;
}

template <typename QElemType> Status QUEUEEMPTY(SqQueue<QElemType> Q) {
	return Q.front == Q.rear;
}

template <typename QElemType> int QUEUELENGTH(SqQueue<QElemType> Q) {
	return Q.rear - Q.front;
}

template <typename QElemType> Status GETHEAD(SqQueue<QElemType> Q, QElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.elem[Q.front + 1];
	return OK;
}

template <typename QElemType> Status ENQUEUE(SqQueue<QElemType>& Q, QElemType item) {
	QElemType* newbase;
	if (Q.rear + 1 == Q.stacksize) {
		newbase = (QElemType*)realloc(Q.elem, (Q.stacksize + QUEUEINCREMENT) * sizeof(QElemType));
		if (!newbase) exit(OVERFLOW);
		Q.elem = newbase;
		Q.stacksize += QUEUEINCREMENT;
	}
	Q.elem[++Q.rear] = item;
	return OK;
}

template <typename QElemType> Status DEQUEUE(SqQueue<QElemType>& Q, QElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.elem[++Q.front];
	return OK;
}

template <typename QElemType> Status PRINTQUEUE(SqQueue<QElemType> Q, Status(*visit)(QElemType)) {
	for (int i = Q.front + 1; i <= Q.rear; i++) visit(Q.elem[i]);
	return OK;
}