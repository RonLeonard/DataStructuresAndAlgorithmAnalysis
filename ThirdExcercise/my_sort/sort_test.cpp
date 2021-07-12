#include "my_sort.h"
#include "the_k_biggest.h"

int main(int argc, char* arg[])
{
	vector<int> ivec;
	ivec.push_back(3);
	ivec.push_back(1);
	ivec.push_back(5);
	ivec.push_back(2);
	ivec.push_back(4);
	printVec(ivec);
	CTheKBiggest theKBiggest(ivec);
	int k = 4, ele = 0;
	theKBiggest.getTheKBiggestElem(k, ele);
	printf("The %d biggest element : %d\n", k, ele);
	mySort(ivec, QUICK_SORT, SMALL2LARGE);
	printVec(ivec);
	return 0;
}