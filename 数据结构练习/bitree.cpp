#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
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
		if (visit(T->data)) if (PREORDERTRAVERSE(T->lchild)) if (PREORDERTRAVERSE(T->rchild)) return OK;
		return ERROR;
	}
	else return OK;
	*/
	return OK;
}

template <typename TElemType> Status INORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType)) {
	/*µÝ¹éËã·¨
	if (T) {
		if (INORDERTRAVERSE(T->lchild)) if (visit(T->data)) if (INORDERTRAVERSE(T->rchild)) return OK;
		return ERROR;
	}
	else return OK;
	*/
	return OK;
}

template <typename TElemType> Status POSTORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType)) {
	/*µÝ¹éËã·¨
	if (T) {
		if (POSTORDERTRAVERSE(T->lchild)) if (POSTORDERTRAVERSE(T->rchild)) if (visit(T->data)) return OK;
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