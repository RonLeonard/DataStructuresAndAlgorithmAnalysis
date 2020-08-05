#include <stdlib.h> 
#include "my_array.h"


#define MALLOC(n,type)  ((type *)malloc((n)* sizeof(type))) 
#define SAFEFREE(ptr) if(ptr!=NULL){ free(ptr); ptr=NULL;}


CMyArray::CMyArray(): length(0), size(5)
{
	pArr = MALLOC(size, int);
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
		val = *(pArr + idx * sizeof(int));
		ret = true;
	}
	return ret;
}



bool CMyArray::insertElem(int val, int idx)
{
	bool ret = false;
	return ret;
}



bool CMyArray::deleteElemOfSpecifiedIdx(int val)
{
	bool ret = false;
	return ret;
}



CMyArray::~CMyArray()
{
	SAFEFREE(pArr);
}