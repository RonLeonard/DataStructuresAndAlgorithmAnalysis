
#include "mySort.h"

namespace sort_alg
{
CMySort::CMySort()
{

}


CMySort::~CMySort()
{

}

/********
*sortType:
		0: small to large
		1: large to small
********/
void CMySort::insertSort(vector<int>& vec, const int sortType)
{
	if (vec.empty())
	return;
	unsigned int n = vec.size();
	int i, j;
	for (i = 1; i < n; i++)
	{
	//from tail to head
	int val = vec.at(i);
	for (j = i - 1; j >= 0; j--)
	{
		if (sortType == LARGE2SAMLL)//large to small
		{
			if (val > vec.at(j))
			{
				vec.at(j + 1) = vec.at(j);
			}
			else
				break;
		}
		else//small to large
		{
			if (val < vec.at(j))
			{
				vec.at(j + 1) = vec.at(j);
			}
			else
				break;
		}
	}
	vec.at(j + 1) = val;
	}
};


/********
*sortType:
		0: small to large
		1: large to small
********/
void CMySort::mergeSort(vector<int>& vec, const int sortType)
{
	int n = vec.size();
	if (n <= 0)
		return;
	mergeSort_imp(vec, sortType, 0, n - 1);
}



void CMySort::mergeSort_imp(vector<int>& vec, const int sortType, int p, int r)
{
	if (p >= r) return;
	int q = p + (r - p) / 2;
	mergeSort_imp(vec, sortType, p, q);
	mergeSort_imp(vec, sortType, q + 1, r);
	//merge(vec, sortType, p, q, r);
	mergeBySentry(vec, sortType, p, q, r);
}



void CMySort::merge(vector<int>& vec, const int sortType, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	vector<int> tmp_vec;
	while (i <= q && j <= r)
	{
		if (sortType == SMALL2LARGE)
		{
			if (vec.at(i) <= vec.at(j))
			{
				tmp_vec.push_back(vec.at(i));
				i++;
			}
			else
			{
				tmp_vec.push_back(vec.at(j));
				j++;
			}
		}
		else
		{
			if (vec.at(i) >= vec.at(j))
			{
				tmp_vec.push_back(vec.at(i));
				i++;
			}
			else
			{
				tmp_vec.push_back(vec.at(j));
				j++;
			}
		}
	}

	while (i <= q)
	{
		tmp_vec.push_back(vec.at(i));
		i++;
	}

	while (j <= r)
	{
		tmp_vec.push_back(vec.at(j));
		j++;
	}

	for (int idx = p; idx <= r; idx++)
	{
		vec.at(idx) = tmp_vec.at(idx - p);
	}
}


void CMySort::mergeBySentry(vector<int>& vec, const int sortType, int p, int q, int r)
{
	vector<int> left;
	vector<int> right;
	for (int i = 0; i <= q - p; i++)
	{
		int ele = vec.at(p + i);
		left.push_back(ele);
	}
	
	
	for (int j = 0; j < r - q; j++)
	{
		int ele = vec.at(q + 1 + j);
		right.push_back(ele);
	}
	if (sortType == SMALL2LARGE)
	{
		left.push_back(INTEGER_MAXIMUM);
		right.push_back(INTEGER_MAXIMUM);
	}
	else
	{
		left.push_back(INTEGER_MINIMUM);
		right.push_back(INTEGER_MINIMUM);
	}

	int idx = p;
	int i = 0, j = 0;
	while (idx <= r)
	{
		if (sortType == SMALL2LARGE)
		{
			if (left.at(i) <= right.at(j))
				vec.at(idx++) = left.at(i++);
			else
				vec.at(idx++) = right.at(j++);
		}
		else
		{
			if (left.at(i) >= right.at(j))
				vec.at(idx++) = left.at(i++);
			else
				vec.at(idx++) = right.at(j++);
		}
	}
}



void CMySort::quickSort(vector<int>& vec, const int sortType)
{
	int n = vec.size();
	quickSort_imp(vec, sortType, 0, n - 1);
}


void CMySort::quickSort_imp(vector<int>& vec, const int sortType, int p, int r)
{
	if (p >= r) return;
	int q = partition(vec, sortType, p, r);
	quickSort_imp(vec, sortType, p, q - 1);
	quickSort_imp(vec, sortType, q + 1, r);
}


int CMySort::partition(vector<int>& vec, const int sortType, int p, int r)
{
	int pivot = vec.at(r);
	int i = p;

	for (int j = p; j < r; j++)
	{
		if (sortType == SMALL2LARGE)
		{
			if (vec.at(j) < pivot)
			{
				swap(vec.at(i), vec.at(j));
				i++;
			}
		}
		else
		{
			if (vec.at(j) > pivot)
			{
				swap(vec.at(i), vec.at(j));
				i++;
			}
		}
	}

	swap(vec.at(i), vec.at(r));
	return i;
}


int CMySort::getKThElem(vector<int>& vec, const int K)
{
	int n = vec.size();
	return getKThElem_imp(vec, K, 0, n - 1);
}


int CMySort::getKThElem_imp(vector<int>& vec, const int K, int p, int r)
{
	if (p > r) return -1;
	int q = partition(vec, SMALL2LARGE, p, r);
	if (q + 1 == K)
		return vec.at(q);
	else if (q + 1 < K)
	{
		return getKThElem_imp(vec, K, q + 1, r);
	}
	else
	{
		return getKThElem_imp(vec, K, p, q - 1);
	}
}




void CMySort::swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

}


