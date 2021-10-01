#include "CppUnitTest.h"
#include "../Abstract Data Type/sorts.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestSorts) {
public:
	TEST_METHOD(TestInsertSort) {
		ElemType M[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
		const ElemType C[] = { 13, 27, 38, 49, 49, 65, 76, 97 };
		INSERTSORT(M, 8);
		for (int i = 0; i < 8; i++) Assert::AreEqual(M[i], C[i]);
	};
	TEST_METHOD(TestBinInsertSort) {
		ElemType M[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
		const ElemType C[] = { 13, 27, 38, 49, 49, 65, 76, 97 };
		BININSERTSORT(M, 8);
		for (int i = 0; i < 8; i++) Assert::AreEqual(M[i], C[i]);
	};
	TEST_METHOD(TestSelectSort) {
		ElemType M[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
		const ElemType C[] = { 13, 27, 38, 49, 49, 65, 76, 97 };
		SELECTSORT(M, 8);
		for (int i = 0; i < 8; i++) Assert::AreEqual(M[i], C[i]);
	};
	TEST_METHOD(TestBubbleSort) {
		ElemType M[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
		const ElemType C[] = { 13, 27, 38, 49, 49, 65, 76, 97 };
		BUBBLESORT(M, 8);
		for (int i = 0; i < 8; i++) Assert::AreEqual(M[i], C[i]);
	};
	TEST_METHOD(TestShellSort) {
		ElemType M[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
		const ElemType C[] = { 13, 27, 38, 49, 49, 65, 76, 97 };
		SHELLSORT(M, 8);
		for (int i = 0; i < 8; i++) Assert::AreEqual(M[i], C[i]);
	};
};