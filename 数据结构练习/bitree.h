#pragma once
#include "base.h"

typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

Status INITBITREE(BiTree& T);
Status CREATEBITREE(BiTree& T, Status(*read)(TElemType&));
Status PREORDERTRAVERSE(BiTree T, Status(*visit)(TElemType));
Status INORDERTRAVERSE(BiTree T, Status(*visit)(TElemType));
Status POSTORDERTRAVERSE(BiTree T, Status(*visit)(TElemType));
Status LEVELORDERTRAVERSE(BiTree T, Status(*visit)(TElemType));