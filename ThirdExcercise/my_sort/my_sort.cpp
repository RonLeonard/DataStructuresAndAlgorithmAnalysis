#include "my_sort.h"



void mySort(vector<int>& ivec, const int method, int sortType)
{
	if (ivec.empty())
		return;
	int n = ivec.size();
	if (method == BUBBLE_SORT)
	{
		int i = 0, j = 0;
		bool flag = false;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n - (i + 1); j++)
			{
				if (sortType == SMALL2LARGE)
				{
					if (ivec.at(j) > ivec.at(j + 1))
					{
						int tmp = ivec.at(j);
						ivec.at(j) = ivec.at(j + 1);
						ivec.at(j + 1) = tmp;
						flag = true;
					}
				}
				else if (sortType == LARGE2SMALL)
				{
					if (ivec.at(j) < ivec.at(j + 1))
					{
						int tmp = ivec.at(j);
						ivec.at(j) = ivec.at(j + 1);
						ivec.at(j + 1) = tmp;
						flag = true;
					}
					
				}
			}
			if (!flag)
				break;
		}
	}
	else if (method == INSERT_SORT)
	{

	}
}


void printVec(const vector<int>& ivec)
{
	for (auto i : ivec)
	{
		printf("%d ", i);
	}
	printf("\n");
}