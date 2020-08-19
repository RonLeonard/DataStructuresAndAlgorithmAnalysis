// myQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "myArrayQueue.h"



using namespace std;

CArrayQueue::CArrayQueue(int n_) : count(0)
{
	this->n = n_;
	head = tail = 0;
	pArray = new int[n] {0};
}



CArrayQueue::~CArrayQueue()
{
	if (pArray != nullptr)
	{
		delete[] pArray;
		pArray = nullptr;
	}
	n = 0;
	count = 0;
	head = tail = 0;
}


/*****this enqueue support resize the memory of queue dynamicly*******/
bool CArrayQueue::enqueue(int val)
{
	if (count == n)
	{
		int* pNewArray = new int[2 * n]{0};
		if (pNewArray == nullptr)
		{
			std::cout << "new pNewArray failed." << endl;
			return false;
		}
		for (int i = 0; i < n; i++)
		{
			pNewArray[i] = pArray[i];
		}
		delete[] pArray;
		pArray = pNewArray;
		n *= 2;
	}
	pArray[count] = val;
	count++;
	return true;
}


/********this dequeue function move the position of every element when it called****************/
int CArrayQueue::dequeue()
{
	if (count == 0)
	{
		cout << "there is no element in myArrayQueue" << endl;
		return -1;
	}

	int headVal = pArray[0];
	for (int i = 0; i < count - 1; i++)
	{
		pArray[i] = pArray[i + 1];
	}
	pArray[count - 1] = 0;
	count--;
	return headVal;
}


void CArrayQueue::printElem()
{
	for (int i = 0; i < count; i++)
	{
		cout << pArray[i] << "\t";
	}
	cout << endl;
}

void CArrayQueue::printElemOfMemory()
{
	for (int i = 0; i < n; i++)
	{
		cout << pArray[i] << "\t";
	}
	cout << endl;
}



bool CArrayQueue::enqueue_1(int val)
{
	if (tail == n)
	{
		if (head == 0)//queue is full.
			return false;
		for (int i = head; i < tail; i++)
		{
			pArray[i - head] = pArray[i];
		}
		
		tail -= head;
		head = 0;
	}

	pArray[tail++] = val;
	return true;
}
int CArrayQueue::dequeue_1()
{
	if (head == tail)
	{
		cout << "there is no element in queue." << endl;
		return -1;
	}

	int ret = pArray[head];
	pArray[head] = 0;
	head++;
	return ret;
}
