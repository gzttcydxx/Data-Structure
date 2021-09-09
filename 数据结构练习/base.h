#pragma once
#pragma warning(disable:4996)

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

template <typename ElemType> Status visit(ElemType e);
template <typename ElemType> Status compare(ElemType e1, ElemType e2);
