#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "linkqueue.h"

Status INITBITREE(BiTree& T) {
	T = (BiTree)malloc(sizeof(BiTNode));
	if (!T) exit(OVERFLOW);
	T->lchild = T->rchild = NULL;
	return OK;
}

Status CREATEBITREE(BiTree& T, FILE* fp) {
	char ch;
	ch = getc(fp);
	if (ch == ' ') T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) exit(OVERFLOW);
		T->data = ch;
		CREATEBITREE(T->lchild, fp);
		CREATEBITREE(T->rchild, fp);
	}
	return OK;
}

Status PREORDERTRAVERSE(BiTree T) {
	/*µÝ¹éËã·¨
	if (T) {
		if (visit(T->data)) if (PREORDERTRAVERSE(T->lchild)) if (PREORDERTRAVERSE(T->rchild)) return OK;
		return ERROR;
	}
	else return OK;
	*/
}

Status INORDERTRAVERSE(BiTree T) {
	/*µÝ¹éËã·¨
	if (T) {
		if (INORDERTRAVERSE(T->lchild)) if (visit(T->data)) if (INORDERTRAVERSE(T->rchild)) return OK;
		return ERROR;
	}
	else return OK;
	*/
}

Status POSTORDERTRAVERSE(BiTree T) {
	/*µÝ¹éËã·¨
	if (T) {
		if (POSTORDERTRAVERSE(T->lchild)) if (POSTORDERTRAVERSE(T->rchild)) if (visit(T->data)) return OK;
		return ERROR;
	}
	else return OK;
	*/
}

Status LEVELORDERTRAVERSE(BiTree T) {
	LinkQueue Q;
	BiTree p;
	INITQUEUE(Q);
	ENQUEUE(Q, T);
	while (!QUEUEEMPTY(Q)) {
		DEQUEUE(Q, p);
		visit(p->data);
		if (p->lchild) ENQUEUE(Q, p->lchild);
		if (p->rchild) ENQUEUE(Q, p->rchild);
	}
	return OK;
}