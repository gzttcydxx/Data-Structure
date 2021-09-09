#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "linkstack.cpp"
#include "linkqueue.cpp"

template <typename TElemType> Status INITBITREE(BiTree<TElemType>& T) {
	T = (BiTree<TElemType>)malloc(sizeof(BiTNode<TElemType>));
	if (!T) exit(OVERFLOW);
	T->lchild = T->rchild = NULL;
	return OK;
}

template <typename TElemType> Status CREATEBITREE(BiTree<TElemType>& T, FILE* fp) {
	char ch;
	ch = getc(fp);
	if (ch == ' ') T = NULL;
	else {
		T = (BiTree<TElemType>)malloc(sizeof(BiTNode<TElemType>));
		if (!T) exit(OVERFLOW);
		T->data = ch;
		CREATEBITREE(T->lchild, fp);
		CREATEBITREE(T->rchild, fp);
	}
	return OK;
}

template <typename TElemType> Status PREORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType)) {
	/*µÝ¹éËã·¨
	if (T) {
		if (visit(T->data)) if (PREORDERTRAVERSE(T->lchild, visit)) if (PREORDERTRAVERSE(T->rchild, visit)) return OK;
		return ERROR;
	}
	else return OK;
	*/
	LinkStack<BiTree<TElemType>> Q;
	BiTree<TElemType> p;
	INITSTACK(Q);
	PUSH(Q, T);
	while (!STACKEMPTY(Q)) {
		POP(Q, p);
		visit(p->data);
		if (p->rchild) PUSH(Q, p->rchild);
		if (p->lchild) PUSH(Q, p->lchild);
	}
	return OK;
}

template <typename TElemType> Status INORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType)) {
	/*µÝ¹éËã·¨
	if (T) {
		if (INORDERTRAVERSE(T->lchild, visit)) if (visit(T->data)) if (INORDERTRAVERSE(T->rchild, visit)) return OK;
		return ERROR;
	}
	else return OK;
	*/
	LinkStack<BiTree<TElemType>> S;
	BiTree<TElemType> p = T;
	INITSTACK(S);
	while (!STACKEMPTY(S) || p) {
		if (p) {
			PUSH(S, p);
			p = p->lchild;
		}
		else {
			POP(S, p);
			visit(p->data);
			p = p->rchild;
		}
	}
	return OK;
}

template <typename TElemType> Status POSTORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType)) {
	/*µÝ¹éËã·¨
	if (T) {
		if (POSTORDERTRAVERSE(T->lchild, visit)) if (POSTORDERTRAVERSE(T->rchild, visit)) if (visit(T->data)) return OK;
		return ERROR;
	}
	else return OK;
	*/
	return OK;
}

template <typename TElemType> Status LEVELORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType)) {
	LinkQueue<BiTree<TElemType>> Q;
	BiTree<TElemType> p;
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