#pragma once
#include "base.h"

template <typename TElemType> struct BiTNode {
	TElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
};
template <typename TElemType> using BiTree = BiTNode<TElemType>*;


template <typename TElemType> Status INITBITREE(BiTree<TElemType>& T);
template <typename TElemType> Status CREATEBITREE(BiTree<TElemType>& T, FILE* fp);
template <typename TElemType> Status PREORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType));
template <typename TElemType> Status INORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType));
template <typename TElemType> Status POSTORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType));
template <typename TElemType> Status LEVELORDERTRAVERSE(BiTree<TElemType> T, Status(*visit)(TElemType));