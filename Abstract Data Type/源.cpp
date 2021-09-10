#include <stdio.h>
#include "base.h"
#include "base.cpp"
#include "bitree.h"
#include "bitree.cpp"

int main() {
	FILE* fp = fopen("bitree.in", "r");
	BiTree<char> T;
	//INITBITREE(T);
	CREATEBITREE(T, fp);
	PREORDERTRAVERSE(T, visit<char>);
	puts("\n");
	INORDERTRAVERSE(T, visit<char>);
	puts("\n");
	POSTORDERTRAVERSE(T, visit<char>);
	puts("\n");
	LEVELORDERTRAVERSE(T, visit<char>);
	fclose(fp);
	return 0;
}