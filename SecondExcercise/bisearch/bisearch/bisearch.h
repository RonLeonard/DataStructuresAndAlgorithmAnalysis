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
	int findVal_byloop(const vector<int>& vec, const int val);
	int findVal_byrecursion(const vector<int>& vec, const int val);
	float findRootOfVal(const float& val, const int& num);
private:
	int findVal_byrecursion_imp(const vector<int>& vec, const int val, int low, int high);
	float findRootOfVal_imp(const float& val, const int& num,  float low, float high);
};



#endif
