#include "CppUnitTest.h"
#include "../数据结构练习/sqstack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestSqStack) {
public:
	SqStack CreateStack() {
		SqStack S;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITSTACK(S);
		for (int i = 0; i < 9; i++) PUSH(S, M[i]);
		return S;
	}
	TEST_METHOD(TestCreateSqStack) {
		int i = 0;
		SqStack S = CreateStack();
		SElemType* p = S.base;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		while (p != S.top) Assert::AreEqual(M[i++], *p++);
	}
	TEST_METHOD(TestPushSqStack) {
		int i = 0;
		SqStack S = CreateStack();
		SElemType* p;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31, 1, 2, 3, 4, 5 };
		Assert::AreEqual(PUSH(S, 1), OK);
		Assert::AreEqual(PUSH(S, 2), OK);
		Assert::AreEqual(PUSH(S, 3), OK);
		Assert::AreEqual(PUSH(S, 4), OK);
		Assert::AreEqual(PUSH(S, 5), OK);
		p = S.base;
		while (p != S.top) Assert::AreEqual(M[i++], *p++);
	}
	TEST_METHOD(TestPopSqStack) {
		int i = 0;
		SqStack S = CreateStack();
		SElemType* p = S.base, e;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 31);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 97);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 32);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 75);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 23);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 7);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 2);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 44);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 1);
		Assert::AreEqual(POP(S, e), ERROR);
		Assert::AreEqual(PUSH(S, 5), OK);
		while (p != S.top) Assert::AreEqual(5, *p++);
	}
	TEST_METHOD(TestGetTop) {
		int i = 0;
		SqStack S;
		SElemType* p, e;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITSTACK(S);
		Assert::AreEqual(GETTOP(S, e), ERROR);
		S = CreateStack();
		Assert::AreEqual(GETTOP(S, e), OK);
		Assert::AreEqual(e, 31);
		p = S.base;
		while (p != S.top) Assert::AreEqual(M[i++], *p++);
	}
};
