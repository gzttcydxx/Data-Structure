#include <stdio.h>
#include <stdlib.h>
#include "sqqueue.h"

Status INITQUEUE(SqQueue& Q) {
	Q.elem = (QElemType*)malloc(QUEUE_INIT_SIZE * sizeof(QElemType));
	if (!Q.elem) exit(OVERFLOW);
	Q.front = -1;
	Q.rear = -1;
	return OK;
}

Status QUEUEEMPTY(SqQueue Q) {
	return Q.front == Q.rear;
}

int QUEUELENGTH(SqQueue Q) {
	return Q.rear - Q.front;
}

Status GETHEAD(SqQueue Q, QElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.elem[Q.front + 1];
	return OK;
}

Status ENQUEUE(SqQueue& Q, QElemType item) {
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

Status DEQUEUE(SqQueue& Q, QElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.elem[++Q.front];
	return OK;
}

Status PRINTQUEUE(SqQueue Q) {
	for (int i = Q.front + 1; i <= Q.rear; i++) visit(Q.elem[i]);
	return OK;
}