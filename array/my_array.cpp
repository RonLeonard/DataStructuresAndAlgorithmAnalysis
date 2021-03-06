#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "my_array.h"


#define MALLOC(n,type)  ((type *)malloc((n)* sizeof(type))) 
#define SAFEFREE(ptr) if(ptr!=NULL){ free(ptr); ptr=NULL;}


CMyArray::CMyArray(int size_): length(0)
{
	size = size_;
	pArr = MALLOC(size, int);
	memset(pArr, 0, size * sizeof(int));
}


bool CMyArray::getValOfSpecifiedIdx(int idx, int &val)
{
	int ret = false;
	if (idx >= length)
	{
		ret = false;
	}
	else
	{
		val = *(pArr + idx);
		ret = true;
	}
	return ret;
}



bool CMyArray::insertElem(int val, int idx)
{
	bool ret = false;
	if (idx > length)
	{
		std::cout << "the idx beyond of the length of myArray" << std::endl;
		return ret;
	}
	//add memory dynamicly
	if (length == size)
	{
		int* pNewArr = MALLOC(size * 2, int);
		memset(pNewArr, 0, size * 2 * sizeof(int));
		for (int i = 0; i < size; i++)
		{
			*(pNewArr + i) = *(pArr + i);
		}
		size *= 2;
		SAFEFREE(pArr);
		pArr = pNewArr;
	}
	
	for (int i = length; i > idx; i--)
	{
		*(pArr + i) = *(pArr + i - 1);
	}

	*(pArr + idx) = val;

	length++;
	ret = true;
	return ret;
}



bool CMyArray::deleteElemOfSpecifiedIdx(int idx)
{
	bool ret = false;
	if (idx >= length)
	{
		std::cout << "the idx beyond of the length of myArray" << std::endl;
		return ret;
	}

	for (int i = idx; i < length - 1; i++)
	{
		*(pArr + i) = *(pArr + i + 1);
	}
	*(pArr + length - 1) = 0;
	length--;
	return true;
}



void CMyArray::printElem()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << *(pArr + i) << " ";
	}
	std::cout << std::endl;
}


int CMyArray::getLength()
{
	return length;
}


CMyArray::~CMyArray()
{
	SAFEFREE(pArr);
}