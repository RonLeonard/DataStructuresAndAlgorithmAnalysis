#ifndef MY_SORT
#define MY_SORT

//#include <stdio.h>
#include <vector>
using namespace std;

enum {
	LARGE2SMALL,
	SMALL2LARGE,
};


enum {
	BUBBLE_SORT,
	INSERT_SORT,
	MERGE_SORT,
	QUICK_SORT,
};


void mySort(vector<int> &ivec, const int method, int sortType);
void printVec(const vector<int>& ivec);
#endif