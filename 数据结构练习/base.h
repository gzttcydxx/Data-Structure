#pragma once
#pragma warning(disable:4996)

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define compare(e1, e2) (e1 == e2 ? TRUE: FALSE)
#define visit(e) (printf("%d ", e))

typedef int Status;
typedef int ElemType;
typedef int SElemType;
typedef int QElemType;
typedef char TElemType;