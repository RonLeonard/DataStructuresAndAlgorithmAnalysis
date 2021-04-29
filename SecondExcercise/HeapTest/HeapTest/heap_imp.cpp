#include "heap_imp.h"

CBigTopHeap::CBigTopHeap()
{

}


CBigTopHeap::~CBigTopHeap()
{

}

//heapify from down to up
void CBigTopHeap::insertElem(const int& data)
{
	if (ivec.empty())
	{
		ivec.push_back(-999);
	}
	ivec.push_back(data);

	int size = ivec.size();
	int idx = size - 1;
	while (idx / 2)
	{
		if (ivec.at(idx) > ivec.at(idx / 2))
		{
			swap(ivec.at(idx), ivec.at(idx / 2));
			idx = idx / 2;
		}
		else
			break;
	}
	return;
}


//heapify from up to bottom
void CBigTopHeap::deleteTopElem()
{
	int size = ivec.size();
	if (size <= 1) //no element
		return;
	ivec.at(1) = ivec.at(size - 1);
	int i = 1;
	while (i)
}