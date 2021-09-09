#include "CppUnitTest.h"
#include "../数据结构练习/sqqueue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestSqQueue) {
public:
	SqQueue<int> CreateQueue() {
		SqQueue<int> Q;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITQUEUE(Q);
		for (int i = 0; i < 9; i++) ENQUEUE(Q, M[i]);
		return Q;
	}
	TEST_METHOD(TestCreateSqQueue) {
		int i = 0, j;
		SqQueue<int> Q = CreateQueue();
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		j = Q.front + 1;
		while (j <= Q.rear) Assert::AreEqual(M[i++], Q.elem[j++]);
	}
	TEST_METHOD(TestEnSqQueue) {
		int i = 0, j;
		SqQueue<int> Q = CreateQueue();
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31, 1, 2, 3, 4, 5 };
		Assert::AreEqual(ENQUEUE(Q, 1), OK);
		Assert::AreEqual(ENQUEUE(Q, 2), OK);
		Assert::AreEqual(ENQUEUE(Q, 3), OK);
		Assert::AreEqual(ENQUEUE(Q, 4), OK);
		Assert::AreEqual(ENQUEUE(Q, 5), OK);
		j = Q.front + 1;
		while (j <= Q.rear) Assert::AreEqual(M[i++], Q.elem[j++]);
	}
	TEST_METHOD(TestDeSqQueue) {
		int i = 0, j;
		SqQueue<int> Q = CreateQueue();
		int e;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 1);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 44);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 2);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 7);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 23);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 75);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 32);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 97);
		Assert::AreEqual(DEQUEUE(Q, e), OK);
		Assert::AreEqual(e, 31);
		Assert::AreEqual(DEQUEUE(Q, e), ERROR);
		Assert::AreEqual(ENQUEUE(Q, 5), OK);
		j = Q.front + 1;
		while (j <= Q.rear) Assert::AreEqual(5, Q.elem[j++]);
	}
	TEST_METHOD(TestGetTop) {
		int i = 0, j;
		SqQueue<int> Q;
		int e;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITQUEUE(Q);
		Assert::AreEqual(GETHEAD(Q, e), ERROR);
		Q = CreateQueue();
		Assert::AreEqual(GETHEAD(Q, e), OK);
		Assert::AreEqual(e, 1);
		j = Q.front + 1;
		while (j <= Q.rear) Assert::AreEqual(M[i++], Q.elem[j++]);
	}
};
