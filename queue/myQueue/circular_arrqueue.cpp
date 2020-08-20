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
	if ((tail + 1) % n == head)//circular queue is full.
	{
		cout << "circular queue is full." << endl;
		return false;
	}
	else
	{
		if (tail != n - 1)
		{
			pArr[tail++] = val;
		}
		else
		{
			pArr[tail] = val;
			tail = 0;
		}
	}
}


int CCircularArrQueue::dequeue()
{
	if (tail == head)
	{
		cout << "circular queue is null." << endl;
		return -1;
	}
	else
	{
		int ret = 0;
		if (head == n - 1)
		{
			ret = pArr[head];
			head = 0;
		}
		else
		{
			ret = pArr[head++];
		}
		return ret;
	}
}



void CCircularArrQueue::printElemOfMemory()
{
	cout << "the circular queue is:" << endl;
	if (head <= tail)
	{
		for (int i = head; i < n; i++)
		{
			cout << pArr[i] << "\t";
		}
	}
	
	for (int i = 0; i <= tail; i++)
	{
		cout << pArr[i] << "\t";
	}
	cout << endl;
	return;
}