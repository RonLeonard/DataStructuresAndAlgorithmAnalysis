#ifndef MY_SORT
#define MY_SORT

//#include <stdio.h>
#include <vector>
using namespace std;

enum {
	LARGE2SMALL = 0,
	SMALL2LARGE,
};


enum SORT_METHOD 
{
	BUBBLE_SORT = 0,
	INSERT_SORT,
	MERGE_SORT,
	QUICK_SORT,
};


void mySort(vector<int> &ivec, const int method, int sortType);

void printVec(const vector<int>& ivec);
#endif