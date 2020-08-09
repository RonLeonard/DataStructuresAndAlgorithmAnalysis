#include <iostream>
#include "arrayStack.h"


CArrayStack::CArrayStack(int n)
{
	this->n = n;
	this->count = 0;
	this->items = new int[n];
}


CArrayStack::~CArrayStack()
{
	delete items;
	n = 0;
	count = 0;
}


bool CArrayStack::push(int val)
{
	if (count == n)
	{
		int* newItems = new int[2 * n];
		for (int i = 0; i < n; i++)
		{
			newItems[i] = items[i];
		}
		delete items;
		items = newItems;
		n *= 2;
	}
		
	items[count] = val;
	count++;
	return true;
}


int CArrayStack::pop()
{
	if (count == 0)
		return -1;
	return items[--count];
}



int CArrayStack::getTopElem()
{
	if (count == 0)
		return -1;
	return items[count - 1];
}

void CArrayStack::printElem()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << items[i];
	}
	std::cout << std::endl;
}


int CArrayStack::getCountOfArrayStack()
{
	return count;
}
