#include "the_k_biggest.h"


CTheKBiggest::CTheKBiggest(const vector<int>& ivec_) : ivec(ivec_)
{

}


CTheKBiggest::~CTheKBiggest()
{

}


int CTheKBiggest::getTheKBiggestElem(int numK, int& theKBiggestElem)
{
	if (numK > ivec.size())
	{
		printf("[%s] numK bigger than the size of ivec\n", __func__);
		return -1;
	}
	theKBiggestElem = getTheKBiggestElemImp(numK, 0, ivec.size() - 1);
	return 0;
}


int CTheKBiggest::getTheKBiggestElemImp(int numK, int p, int r)
{
	int q = partitionImp(p, r);
	printf("p = %d, q = %d, r = %d\n", p, q, r);
	if (numK == (ivec.size() - q))
		return ivec[q];
	else if (numK < (ivec.size() - q))
	{
		getTheKBiggestElemImp(numK, q + 1, r);
	}
	else
	{
		getTheKBiggestElemImp(numK, p, q - 1);
	}
}

int CTheKBiggest::partitionImp(int p, int r)
{
	int pivot = ivec[r];
	int i = p;
	for (int j = p; j < r; j++)
	{
		if (ivec[j] < pivot)
		{
			if (i == j)
			{
				i++;
			}
			else
			{
				int tmp = ivec[i];
				ivec[i] = ivec[j];
				ivec[j] = tmp;
				i++;
			}
		}
	}
	ivec[r] = ivec[i];
	ivec[i] = pivot;
	return i;
}