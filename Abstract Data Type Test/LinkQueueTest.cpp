#include "CppUnitTest.h"
#include "../Abstract Data Type/linkqueue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestLinkQueue) {
public:
	LinkQueue<int> CreateQueue() {
		LinkQueue<int> Q;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITQUEUE(Q);
		for (int i = 0; i < 9; i++) ENQUEUE(Q, M[i]);
		return Q;
	}
	TEST_METHOD(TestCreateLinkQueue) {
		int i = 0;
		LinkQueue<int> Q = CreateQueue();
		QueuePtr<int> p = Q.front->next;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		while (p) {
			Assert::AreEqual(M[i++], p->data);
			p = p->next;
		}
	}
	TEST_METHOD(TestEnLinkQueue) {
		int i = 0;
		LinkQueue<int> Q = CreateQueue();
		QueuePtr<int> p;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31, 1, 2, 3, 4, 5 };
		Assert::AreEqual(ENQUEUE(Q, 1), OK);
		Assert::AreEqual(ENQUEUE(Q, 2), OK);
		Assert::AreEqual(ENQUEUE(Q, 3), OK);
		Assert::AreEqual(ENQUEUE(Q, 4), OK);
		Assert::AreEqual(ENQUEUE(Q, 5), OK);
		p = Q.front->next;
		while (p) {
			Assert::AreEqual(M[i++], p->data);
			p = p->next;
		}
	}
	TEST_METHOD(TestDeLinkQueue) {
		LinkQueue<int> Q = CreateQueue();
		int e;
		QueuePtr<int> p;
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
		p = Q.front->next;
		while (p) {
			Assert::AreEqual(5, p->data);
			p = p->next;
		}
	}
	TEST_METHOD(TestGetTop) {
		int i = 0;
		LinkQueue<int> Q;
		int e;
		QueuePtr<int> p;
		const int M[] = { 1, 44, 2, 7, 23, 75, 32, 97, 31 };
		INITQUEUE(Q);
		Assert::AreEqual(GETHEAD(Q, e), ERROR);
		Q = CreateQueue();
		Assert::AreEqual(GETHEAD(Q, e), OK);
		Assert::AreEqual(e, 1);
		p = Q.front->next;
		while (p) {
			Assert::AreEqual(M[i++], p->data);
			p = p->next;
		}
	}
};
