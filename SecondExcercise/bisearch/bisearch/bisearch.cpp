#include "bisearch.h"


CBisearch::CBisearch()
{

}


CBisearch::~CBisearch()
{

}


int CBisearch::findVal_byloop(const vector<int>& vec, const int val)
{
	int n = vec.size();
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if (vec.at(mid) == val)
			return mid;
		else if (vec.at(mid) < val)
		{
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return -1;
}


int CBisearch::findVal_byrecursion(const vector<int>& vec, const int val)
{
	int n = vec.size();
	return findVal_byrecursion_imp(vec, val, 0, n - 1);
}


int CBisearch::findVal_byrecursion_imp(const vector<int>& vec, const int val, int low, int high)
{
	if (low > high) return -1;
	int mid = low + ((high - low) >> 1);
	if (vec.at(mid) == val)
		return mid;
	else if (vec.at(mid) < val)
		return findVal_byrecursion_imp(vec, val, mid + 1, high);
	else
		return findVal_byrecursion_imp(vec, val, low, mid - 1);
}


float CBisearch::findRootOfVal(const float& val, const int& num)
{
	return findRootOfVal_imp(val, num, 0, val);
}


float CBisearch::findRootOfVal_imp(const float& val, const int& num, float low, float high)
{
	float root = low + ((high - low) / 2.0);
	if (fabs(root * root - val) <= pow(0.1, num))
	{
		return root;
	}
	else if ((root * root - val) > pow(0.1, num))
	{
		return findRootOfVal_imp(val, num, low, root);
	}
	else
	{
		return findRootOfVal_imp(val, num, root, high);
	}
}



