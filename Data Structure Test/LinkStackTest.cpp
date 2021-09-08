#include "CppUnitTest.h"
#include "../数据结构练习/linkstack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestLinkStack) {
public:
	LinkStack CreateStack() {
		LinkStack S;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITSTACK(S);
		for (int i = 8; i >= 0; i--) PUSH(S, M[i]);
		return S;
	}
	TEST_METHOD(TestCreateLinkStack) {
		int i = 0;
		LinkStack S = CreateStack(), p = S->next;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		while (p) {
			Assert::AreEqual(M[i++], p->data);
			p = p->next;
		}
	}
	TEST_METHOD(TestPushLinkStack) {
		int i = 0;
		LinkStack S = CreateStack(), p;
		const int M[] = { 5, 4, 3, 2, 1, 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		Assert::AreEqual(PUSH(S, 1), OK);
		Assert::AreEqual(PUSH(S, 2), OK);
		Assert::AreEqual(PUSH(S, 3), OK);
		Assert::AreEqual(PUSH(S, 4), OK);
		Assert::AreEqual(PUSH(S, 5), OK);
		p = S->next;
		while (p) {
			Assert::AreEqual(M[i++], p->data);
			p = p->next;
		}
	}
	TEST_METHOD(TestPopLinkStack) {
		int i = 0;
		LinkStack S = CreateStack(), p;
		SElemType e;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 1);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 44);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 2);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 7);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 23);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 75);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 32);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 97);
		Assert::AreEqual(POP(S, e), OK);
		Assert::AreEqual(e, 31);
		Assert::AreEqual(POP(S, e), ERROR);
		Assert::AreEqual(PUSH(S, 5), OK);
		p = S->next;
		while (p) {
			Assert::AreEqual(5, p->data);
			p = p->next;
		}
	}
	TEST_METHOD(TestGetTop) {
		int i = 0;
		LinkStack S = CreateStack(), p;
		SElemType e;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITSTACK(S);
		Assert::AreEqual(GETTOP(S, e), ERROR);
		S = CreateStack();
		Assert::AreEqual(GETTOP(S, e), OK);
		Assert::AreEqual(e, 1);
		p = S->next;
		while (p) {
			Assert::AreEqual(M[i++], p->data);
			p = p->next;
		}
	}
};
