#include "CppUnitTest.h"
#include "../数据结构练习/linklist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestLinkList) {
public:
	LinkList CreateList() {
		LinkList L;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITLINKLIST(L);
		for (int i = 8; i >= 0; i--) INSERTLINKLIST(L, 1, M[i]);
		return L;
	}
	TEST_METHOD(TestCreateSqList) {
		int i = 0;
		LinkList L = CreateList(), p = L->next;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		while (p) {
			Assert::AreEqual(M[i], p->data);
			p = p->next;
			i++;
		}
	};
	TEST_METHOD(TestInsertSqList) {
		int i = 0;
		LinkList L = CreateList(), p;
		int M[] = { 1000, 1, 0, 44, 2, 7, 23, 75, 32, 97, 31, 1 };
		Assert::AreEqual(INSERTLINKLIST(L, -2, 0), ERROR);
		Assert::AreEqual(INSERTLINKLIST(L, 200, 0), ERROR);
		Assert::AreEqual(INSERTLINKLIST(L, 2, 0), OK);
		Assert::AreEqual(INSERTLINKLIST(L, 11, 1), OK);
		Assert::AreEqual(INSERTLINKLIST(L, 1, 1000), OK);
		p = L->next;
		while (p) {
			Assert::AreEqual(M[i], p->data);
			p = p->next;
			i++;
		}
	};
	TEST_METHOD(TestDeleteSqList) {
		int i = 0;
		LinkList L = CreateList(), p;
		ElemType e;
		const int M[] = { 44, 2, 7, 23, 32, 97 };
		Assert::AreEqual(DELETELINKLIST(L, 1, e), OK);
		Assert::AreEqual(e, 1);
		Assert::AreEqual(DELETELINKLIST(L, -1, e), ERROR);
		Assert::AreEqual(DELETELINKLIST(L, 1000, e), ERROR);
		Assert::AreEqual(DELETELINKLIST(L, 5, e), OK);
		Assert::AreEqual(e, 75);
		Assert::AreEqual(DELETELINKLIST(L, 7, e), OK);
		Assert::AreEqual(e, 31);
		p = L->next;
		while (p) {
			Assert::AreEqual(M[i], p->data);
			p = p->next;
			i++;
		}
	}
	TEST_METHOD(TestLocateElement) {
		LinkList L = CreateList();
		Assert::AreEqual(LOCATEELEM(L, 97), 8);
		Assert::AreEqual(LOCATEELEM(L, 971), 0);
		Assert::AreEqual(LOCATEELEM(L, 1), 1);
		Assert::AreEqual(LOCATEELEM(L, 31), 9);
	}
};