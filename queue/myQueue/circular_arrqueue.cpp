#include <iostream>
#include "circular_arrqueue.h"

using namespace std;
CCircularArrQueue::CCircularArrQueue(int _n)
{
	n = _n;
	pArr = new int[n] {0};
	if (pArr == nullptr)
	{
		cout << "new pArr failed." << endl;
	}
}


CCircularArrQueue::~CCircularArrQueue()
{
	if (pArr != nullptr)
	{
		delete[] pArr;
		pArr = nullptr;
	}
	n = 0;
	head = 0;
	tail = 0;
	count = 0;
}


bool CCircularArrQueue::enqueue(int val)
{

}


int CCircularArrQueue::dequeue()
{

}



int CCircularArrQueue::printElemOfMemory()
{

}