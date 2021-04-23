#include "recursion_tree.h"



void CRecursionTree::printRermutations(int n, int k)
{
	if (k == 1)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", ivec[i]);
		}
		printf("\n");
	}

	for (int i = 0; i < k; i++)
	{
		int tmp = ivec[i];
		ivec[i] = ivec[size_t(k) -1] ;
		ivec[size_t(k) - 1] = tmp;
		printRermutations(n, k - 1);
		tmp = ivec[i];
		ivec[i] = ivec[size_t(k) - 1];
		ivec[size_t(k) - 1] = tmp;
	}
}


void CRecursionTree::putInElem(int ele)
{
	ivec.push_back(ele);
	return;
}