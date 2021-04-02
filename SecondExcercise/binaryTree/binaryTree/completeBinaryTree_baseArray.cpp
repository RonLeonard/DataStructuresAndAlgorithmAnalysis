#include<stdio.h>
#include "completeBinaryTree_baseArray.h"



CCompleteBiTreeBaseArray::CCompleteBiTreeBaseArray()
{
	ivec.push_back(0);
}


CCompleteBiTreeBaseArray::~CCompleteBiTreeBaseArray()
{

}


void CCompleteBiTreeBaseArray::putInVec(vector<int>& input)
{
	vector<int>::iterator it;
	for (it = input.begin(); it != input.end(); it++)
	{
		ivec.push_back(*it);
	}
}


void CCompleteBiTreeBaseArray::preOrder()
{


}


void CCompleteBiTreeBaseArray::inOrder()
{

}


void CCompleteBiTreeBaseArray::postOrder()
{


}


void CCompleteBiTreeBaseArray::printVec(const vector<int>& vec)
{
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		printf("%d ", *it);
	}
	printf("\n");
}