#include <stdio.h>
#include "base.h"

Status compare(ElemType e1, ElemType e2) {
	if (e1 == e2) return TRUE;
	else return FALSE;
}

Status visit(ElemType item) {
	printf("%d ", item);
	return OK;
}