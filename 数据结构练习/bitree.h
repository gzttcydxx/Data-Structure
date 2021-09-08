#pragma once
#include "base.h"



Status INITBITREE(BiTree& T);
Status CREATEBITREE(BiTree& T, FILE* fp);
Status PREORDERTRAVERSE(BiTree T);
Status INORDERTRAVERSE(BiTree T);
Status POSTORDERTRAVERSE(BiTree T);
Status LEVELORDERTRAVERSE(BiTree T);