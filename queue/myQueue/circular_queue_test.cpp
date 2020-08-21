//#define CIRCULAR_QUEUE_TEST
#ifndef CIRCULAR_QUEUE_TEST


#include <iostream>
#include "circular_arrqueue.h"

int main(int argc, char** argv)
{

	CCircularArrQueue* pCCircularArrQueue = new CCircularArrQueue(5);

	pCCircularArrQueue->enqueue(1);
	pCCircularArrQueue->enqueue(2);
	pCCircularArrQueue->enqueue(3);
	pCCircularArrQueue->enqueue(4);
	
	pCCircularArrQueue->dequeue();
	pCCircularArrQueue->dequeue();
	pCCircularArrQueue->enqueue(5);
	pCCircularArrQueue->enqueue(6);
	pCCircularArrQueue->printElemOfMemory();
	delete pCCircularArrQueue;
	pCCircularArrQueue = nullptr;
	return 0;
}


#endif