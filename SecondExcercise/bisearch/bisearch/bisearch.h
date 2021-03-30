#ifndef _BISEARCH_H
#define _BISEARCH_H

#include <iostream>
#include <vector>
using namespace std;

class CBisearch
{
public:
	CBisearch();
	~CBisearch();
/*
*note: these bisearch method based on the sorted array that from small to large.
*/
	/*find the specified val*/
	int findVal_byloop(const vector<int>& vec, const int val);
	int findVal_byrecursion(const vector<int>& vec, const int val);
	/*find the first element that val equal with the specified val*/
	int findFirstElement(const vector<int>& vec, const int val);
	int findLastElement(const vector<int>& vec, const int val);
	int findFirstBiggerOrEqualElement(const vector<int>& vec, const int val);
	int findLastSmallerOrEqualElement(const vector<int>& vec, const int val);

	/*sqrt imp*/
	float findRootOfVal(const float& val, const int& num);
private:
	int findVal_byrecursion_imp(const vector<int>& vec, const int val, int low, int high);
	float findRootOfVal_imp(const double& val, const int& num, double low, double high);
};



#endif
