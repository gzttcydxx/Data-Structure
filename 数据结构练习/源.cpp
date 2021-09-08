#include <stdio.h>
#include "bitree.h"

int main() {
	FILE* fp = fopen("bitree.in", "r");
	BiTree T;
	//INITBITREE(T);
	CREATEBITREE(T, fp);
	PREORDERTRAVERSE(T);
	puts("\n");
	INORDERTRAVERSE(T);
	puts("\n");
	POSTORDERTRAVERSE(T);
	puts("\n");
	LEVELORDERTRAVERSE(T);
	fclose(fp);
	return 0;
}