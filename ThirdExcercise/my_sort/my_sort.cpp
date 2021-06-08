#include "my_sort.h"


void merge(vector<int>& ivec, int p, int q, int r, int sortType)
{
	int k = 0;
	vector<int> tmpVec;
	int i = p;
	int j = q + 1;
	while (i <= q && j <= r)
	{
		if (sortType == SMALL2LARGE)
		{
			if (ivec.at(i) <= ivec.at(j))
			{
				tmpVec.push_back(ivec.at(i));
				i++;
			}
			else
			{
				tmpVec.push_back(ivec.at(j));
				j++;
			}
		}
		else
		{
			if (ivec.at(i) >= ivec.at(j))
			{
				tmpVec.push_back(ivec.at(i));
				i++;
			}
			else
			{
				tmpVec.push_back(ivec.at(j));
				j++;
			}
		}
	}

	while (i <= q)
	{
		tmpVec.push_back(ivec.at(i));
		i++;
	}
	while (j <= r)
	{
		tmpVec.push_back(ivec.at(j));
		j++;
	}
	//copy tmpVec to ivec
	for (int idx = 0; idx < tmpVec.size(); idx++)
	{
		ivec.at(p + idx) = tmpVec.at(idx);
	}
}

void mergeSort_imp(vector<int>& ivec, int p, int r, int sortType)
{
	if (p >= r)
		return;
	int q = p + ((r - p) >> 1);
	mergeSort_imp(ivec, p, q, sortType);
	mergeSort_imp(ivec, q + 1, r, sortType);
	merge(ivec, p, q, r, sortType);
}


void mySort(vector<int>& ivec, const int method, int sortType)
{
	if (ivec.empty())
		return;
	size_t n = ivec.size();
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
		//first loop appoint the position that will be sorted
		for (int i = 1; i < n; i++)
		{
			int value = ivec[i];
			int j = 0;
			//this loop use to searh the insert position
			for (j = i - 1; j >= 0; j--)
			{
				if (sortType == SMALL2LARGE)
				{
					if (value < ivec[j])
					{
						ivec.at(j + 1) = ivec.at(j);
					}
					else
						break;
				}
				else
				{
					if (value > ivec[j])
					{
						ivec.at(j + 1) = ivec.at(j);
					}
					else
						break;
				}
			}
			ivec.at(j + 1) = value;
		}
	}
	else if (method == MERGE_SORT)
	{
		mergeSort_imp(ivec, 0, ivec.size() - 1, sortType);
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