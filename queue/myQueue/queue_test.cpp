//#define QUEUE_TEST
#ifndef QUEUE_TEST

#include <iostream>
#include "myArrayQueue.h"

using namespace std;


int main(int argc, char **argv)
{

	CArrayQueue* pArrQueue = new CArrayQueue(5);

	pArrQueue->enqueue(5);
	pArrQueue->enqueue(3);
	pArrQueue->enqueue(1);

	cout << "the element of queue memory is:" << endl;
	//pArrQueue->printElem();
	pArrQueue->printElemOfMemory();

	pArrQueue->dequeue();
	cout << "after dequeue the element of queue memory is:" << endl;
	//pArrQueue->printElem();
	pArrQueue->printElemOfMemory();
	pArrQueue->dequeue();
	cout << "after dequeue the element of queue memory is:" << endl;
	//pArrQueue->printElem();
	pArrQueue->printElemOfMemory();
	pArrQueue->enqueue(2);
	pArrQueue->enqueue(4);
	pArrQueue->printElemOfMemory();
	pArrQueue->enqueue(5);
	pArrQueue->enqueue(6);
	cout << "the element of queue memory is:" << endl;
	pArrQueue->printElemOfMemory();
	pArrQueue->enqueue(7);
	cout << "the element of queue memory is:" << endl;
	pArrQueue->printElemOfMemory();
	delete pArrQueue;
	pArrQueue = nullptr;

	cout << "other methods of enqueue and dequeue is below:" << endl;
	CArrayQueue* pArrQueue_1 = new CArrayQueue(5);
	pArrQueue_1->enqueue_1(1);
	pArrQueue_1->enqueue_1(2);
	pArrQueue_1->enqueue_1(3);
	cout << "the element of queue memory is:" << endl;
	pArrQueue_1->printElemOfMemory();
	pArrQueue_1->dequeue_1();
	cout << "the element of queue memory is:" << endl;
	pArrQueue_1->printElemOfMemory();
	pArrQueue_1->enqueue_1(4);
	pArrQueue_1->enqueue_1(5);
	pArrQueue_1->enqueue_1(6);
	cout << "the element of queue memory is:" << endl;
	pArrQueue_1->printElemOfMemory();
}

#endif