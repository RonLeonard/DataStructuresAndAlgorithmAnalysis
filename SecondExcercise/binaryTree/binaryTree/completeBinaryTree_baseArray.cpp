#include<stdio.h>
#include "completeBinaryTree_baseArray.h"



CCompleteBiTreeBaseArray::CCompleteBiTreeBaseArray()
{
	ivec.push_back(0);
}


CCompleteBiTreeBaseArray::~CCompleteBiTreeBaseArray()
{

}


void CCompleteBiTreeBaseArray::putInVec(const int& input)
{
	ivec.push_back(input);
}


void CCompleteBiTreeBaseArray::preOrder()
{
	preOrder_imp(1);
}

void CCompleteBiTreeBaseArray::preOrder_imp(const int idx)
{
	if (idx >= ivec.size())
		return;
	printf("%d ", ivec.at(idx));
	preOrder_imp(2 * idx);
	preOrder_imp(2 * idx + 1);
}


void CCompleteBiTreeBaseArray::inOrder()
{
	inOrder_imp(1);
}


void CCompleteBiTreeBaseArray::inOrder_imp(const int idx)
{
	if (idx >= ivec.size())
		return;
	inOrder_imp(2 * idx);
	printf("%d ", ivec.at(idx));
	inOrder_imp(2 * idx + 1);
}


void CCompleteBiTreeBaseArray::postOrder()
{
	postOrder_imp(1);
}


void CCompleteBiTreeBaseArray::postOrder_imp(const int idx)
{
	if (idx >= ivec.size())
		return;
	postOrder_imp(2 * idx);
	postOrder_imp(2 * idx + 1);
	printf("%d ", ivec.at(idx));
}

void CCompleteBiTreeBaseArray::printVec()
{
	vector<int>::iterator it;
	for (it = ivec.begin(); it != ivec.end(); it++)
	{
		printf("%d ", *it);
	}
	printf("\n");
}