#pragma once
#include "base.h"

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

Status INITBITREE(BiTree& T);
Status PREORDERTRAVERSE(BiTree T, Status(*visit)(ElemType));
Status INORDERTRAVERSE(BiTree T, Status(*visit)(ElemType));
Status POSTORDERTRAVERSE(BiTree T, Status(*visit)(ElemType));
Status LEVELORDERTRAVERSE(BiTree T, Status(*visit)(ElemType));