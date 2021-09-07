#include <stdio.h>
#include <stdlib.h>
#include "sqqueue.h"

Status INITQUEUE(SqQueue& Q) {
	Q.elem = (ElemType*)malloc(QUEUE_INIT_SIZE * sizeof(ElemType));
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

Status GETHEAD(SqQueue Q, ElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.elem[Q.front];
	return OK;
}

Status ENQUEUE(SqQueue& Q, ElemType item) {
	ElemType* newbase;
	if (Q.front + 1 == Q.stacksize) {
		newbase = (ElemType*)realloc(Q.elem, (Q.stacksize + QUEUEINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		Q.elem = newbase;
		Q.stacksize += QUEUEINCREMENT;
	}
	Q.elem[++Q.front] = item;
	return OK;
}

Status DEQUEUE(SqQueue& Q, ElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.elem[++Q.rear];
	return OK;
}

Status PRINTQUEUE(SqQueue Q) {
	for (int i = Q.rear + 1; i <= Q.front; i++) printf("%d ", Q.elem[i]);
	return OK;
}