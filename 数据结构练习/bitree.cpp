#include <stdlib.h>
#include "bitree.h"
#include "linkqueue.h"

Status INITBITREE(BiTree& T) {
	T = (BiTree)malloc(sizeof(BiTNode));
	if (!T) exit(OVERFLOW);
	T->lchild = T->rchild = NULL;
	return OK;
}

Status CREATEBITREE(BiTree& T, Status(*read)(TElemType&)) {
	char ch;
	(*read)(ch);
	if (ch == ' ') T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) exit(OVERFLOW);
		T->data = ch;
		CREATEBITREE(T->lchild, *read);
		CREATEBITREE(T->rchild, *read);
	}
	return OK;
}


Status PREORDERTRAVERSE(BiTree T, Status(*visit)(TElemType)) {
	if ((*visit)(T->data)) if (PREORDERTRAVERSE(T->lchild, *visit)) if (PREORDERTRAVERSE(T->rchild, *visit)) return OK;
	return ERROR;
}

Status INORDERTRAVERSE(BiTree T, Status(*visit)(TElemType)) {
	if (PREORDERTRAVERSE(T->lchild, *visit)) if ((*visit)(T->data)) if (PREORDERTRAVERSE(T->rchild, *visit)) return OK;
	return ERROR;
}

Status POSTORDERTRAVERSE(BiTree T, Status(*visit)(TElemType)) {
	if (PREORDERTRAVERSE(T->lchild, *visit)) if (PREORDERTRAVERSE(T->rchild, *visit)) if ((*visit)(T->data)) return OK;
	return ERROR;
}

Status LEVELORDERTRAVERSE(BiTree T, Status(*visit)(TElemType)) {
	LinkQueue Q;
	INITQUEUE(Q);
	//ENQUEUE(Q, T);
	return OK;
}