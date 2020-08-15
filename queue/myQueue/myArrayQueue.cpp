// myQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "myArrayQueue.h"



using namespace std;

CArrayQueue::CArrayQueue(int n_) : count(0)
{
	this->n = n_;
	pArray = new int[n];
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
}



bool CArrayQueue::enqueue(int val)
{
	if (count == n)
	{
		int* pNewArray = new int[2 * n];
		if (pNewArray == nullptr)
		{
			std::cout << "new pNewArray failed." << endl;
			return false;
		}
		for (int i = 0; i < n; i++)
		{
			pNewArray[i] = pArray[i];
		}
		pArray = pNewArray;
		delete[] pNewArray;
		pNewArray = nullptr;
		n *= 2;
	}
	pArray[count] = val;
	count++;
	return true;
}



int CArrayQueue::dequeue()
{
	if (count == 0)
	{
		cout << "there is no element in myArrayQueue" << endl;
		return -1;
	}

	int headVal = pArray[0];
	for (int i = 0; i < count; i++)
	{
		pArray[i] = pArray[i + 1];
	}
	pArray[count] = 0;
	count--;
	return headVal;
}

