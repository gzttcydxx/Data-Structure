#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

template <typename QElemType> Status INITQUEUE(LinkQueue<QElemType>& Q) {
	Q.front = Q.rear = (QueuePtr<QElemType>)malloc(sizeof(QNode<QElemType>));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

template <typename QElemType> Status QUEUEEMPTY(LinkQueue<QElemType> Q) {
	return Q.front == Q.rear;
}

template <typename QElemType> int QUEUELENGTH(LinkQueue<QElemType> Q) {
	int i = 0;
	QueuePtr<QElemType> p = Q.front->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

template <typename QElemType> Status GETHEAD(LinkQueue<QElemType> Q, QElemType& item) {
	if (QUEUEEMPTY(Q)) return ERROR;
	item = Q.front->next->data;
	return OK;
}

template <typename QElemType> Status ENQUEUE(LinkQueue<QElemType>& Q, QElemType item) {
	QueuePtr<QElemType> p = (QueuePtr<QElemType>)malloc(sizeof(QNode<QElemType>));
	if (!p) exit(OVERFLOW);
	p->data = item;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

template <typename QElemType> Status DEQUEUE(LinkQueue<QElemType>& Q, QElemType& item) {
	QueuePtr<QElemType> p;
	if (QUEUEEMPTY(Q)) return ERROR;
	p = Q.front->next;
	item = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}

template <typename QElemType> Status PRINTQUEUE(LinkQueue<QElemType> Q) {
	QueuePtr<QElemType> p = Q.front->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	return OK;
}