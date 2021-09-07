#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

Status INITQUEUE(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status QUEUEEMPTY(LinkQueue Q) {
	return Q.front == Q.rear;
}

int QUEUELENGTH(LinkQueue Q) {
	int i = 0;
	QueuePtr p = Q.front->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

Status GETHEAD(LinkQueue Q, ElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.front->next->data;
	return OK;
}

Status ENQUEUE(LinkQueue& Q, ElemType item) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = item;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DEQUEUE(LinkQueue& Q, ElemType& item) {
	QueuePtr p;
	if (QUEUEEMPTY(Q)) return ERROR;
	p = Q.front->next;
	item = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}

Status PRINTQUEUE(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}