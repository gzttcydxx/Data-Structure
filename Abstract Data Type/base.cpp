#include <iostream>
#include "base.h"

template <typename ElemType> Status visit(ElemType e) {
	std::cout << e << ' ';
	return OK;
}

template <typename ElemType> Status compare(ElemType e1, ElemType e2) {
	return e1 == e2;
}