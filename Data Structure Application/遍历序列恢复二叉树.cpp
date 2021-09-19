#include <stdio.h>
#include <stdlib.h>
#include "../Abstract Data Type/base.cpp"
#include "../Abstract Data Type/bitree.cpp"

BiTree<char> PreInOrder(char* pre, char* in, int size) {
	BiTree<char> T;
	for (int i = 0; i < size; i++) if (*pre == *(in + i)) {
		T = (BiTree<char>)malloc(sizeof(BiTNode<char>));
		if (!T) exit(OVERFLOW);
		T->data = *(in + i);
		T->lchild = PreInOrder(pre + 1, in, i);
		T->rchild = PreInOrder(pre + i + 1, in + i + 1, size - i - 1);
		return T;
	}
	return NULL;
}

BiTree<char> PostInOrder(char* post, char* in, int size) {
	BiTree<char> T;
	for (int i = 0; i < size; i++) if (*(post + size - 1) == *(in + i)) {
		T = (BiTree<char>)malloc(sizeof(BiTNode<char>));
		if (!T) exit(OVERFLOW);
		T->data = *(in + i);
		T->lchild = PostInOrder(post, in, i);
		T->rchild = PostInOrder(post + i, in + i + 1, size - i - 1);
		return T;
	}
	return NULL;
}

BiTree<char> LevelInOrder(BiTree<char> T, char* level, char* in, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) if (*(level + i) == *(in + j)) {
			T = (BiTree<char>)malloc(sizeof(BiTNode<char>));
			if (!T) exit(OVERFLOW);
			T->data = *(in + j);
		}
	}
}

int main() {
	BiTree<char> T;
	char pre[] = "ABCDEFG";
	char in[] = "DCBAEFG";
	char post[] = "DCBGFEA";
	int size = 7;
	T = PreInOrder(pre, in, size);
	printf("后序遍历：");
	POSTORDERTRAVERSE(T, visit);
	T = PostInOrder(post, in, size);
	printf("\n先序遍历：");
	PREORDERTRAVERSE(T, visit);
	return 0;
}