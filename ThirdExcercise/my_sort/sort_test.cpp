#include "my_sort.h"


int main(int argc, char* arg[])
{
	vector<int> ivec;
	ivec.push_back(3);
	ivec.push_back(1);
	ivec.push_back(5);
	ivec.push_back(2);
	ivec.push_back(4);
	printVec(ivec);
	mySort(ivec, BUBBLE_SORT, SMALL2LARGE);
	printVec(ivec);
	return 0;
}