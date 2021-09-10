#include "CppUnitTest.h"
#include "../Abstract Data Type/base.cpp"
#include "../Abstract Data Type/sqlist.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestSqList) {
public:
	SqList<int> CreateList() {
		SqList<int> L;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITLIST(L);
		for (int i = 8; i >= 0; i--) INSERTLIST(L, 1, M[i]);
		return L;
	}
	TEST_METHOD(TestCreateSqList) {
		SqList<int> L = CreateList();
		Assert::AreEqual(L.length, 9);
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		for (int i = 0; i < L.length; i++) Assert::AreEqual(M[i], L.elem[i]);
	};
	TEST_METHOD(TestInsertSqList) {
		SqList<int> L = CreateList();
		int M[] = { 1000, 1, 0, 44, 2, 7, 23, 75, 32, 97, 31, 1 };
		Assert::AreEqual(INSERTLIST(L, -2, 0), ERROR);
		Assert::AreEqual(INSERTLIST(L, 200, 0), ERROR);
		Assert::AreEqual(INSERTLIST(L, 2, 0), OK);
		Assert::AreEqual(INSERTLIST(L, 11, 1), OK);
		Assert::AreEqual(INSERTLIST(L, 1, 1000), OK);
		for (int i = 0; i < L.length; i++) Assert::AreEqual(M[i], L.elem[i]);
	};
	TEST_METHOD(TestDeleteSqList) {
		SqList<int> L = CreateList();
		int e;
		const int M[] = { 44, 2, 7, 23, 32, 97 };
		Assert::AreEqual(DELETELIST(L, 1, e), OK);
		Assert::AreEqual(e, 1);
		Assert::AreEqual(DELETELIST(L, -1, e), ERROR);
		Assert::AreEqual(DELETELIST(L, 1000, e), ERROR);
		Assert::AreEqual(DELETELIST(L, 5, e), OK);
		Assert::AreEqual(e, 75);
		Assert::AreEqual(DELETELIST(L, 7, e), OK);
		Assert::AreEqual(e, 31);
		for (int i = 0; i < L.length; i++) Assert::AreEqual(M[i], L.elem[i]);
	}
	TEST_METHOD(TestLocateElement) {
		SqList<int> L = CreateList();
		Assert::AreEqual(LOCATEELEM(L, 97, compare), 8);
		Assert::AreEqual(LOCATEELEM(L, 971, compare), 0);
		Assert::AreEqual(LOCATEELEM(L, 1, compare), 1);
		Assert::AreEqual(LOCATEELEM(L, 31, compare), 9);
	}
};
