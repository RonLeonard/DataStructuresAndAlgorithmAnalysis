#include <iostream>
#include "bisearch.h"

using namespace std;
void test_findVal_byloop(const vector<int>& vec, const int val)
{
	CBisearch bisearch;
	int i = bisearch.findVal_byloop(vec, val);
	if (i == -1)
	{
		cout << "val is no found" << endl;
	}
	else
	{
		cout << "idx = " << i << endl;
	}
}


void test_findVal_byrecursion(const vector<int>& vec, const int val)
{
	cout << "test_findVal_byrecursion" << endl;
	CBisearch bisearch;
	int i = bisearch.findVal_byrecursion(vec, val);
	if (i == -1)
	{
		cout << "val is no found" << endl;
	}
	else
	{
		cout << "idx = " << i << endl;
	}
}


void test_findRootOfVal(const int& val, const int& num)
{
	CBisearch bisearch;
	float root = bisearch.findRootOfVal(val, num);
	printf("the root of val is %f", root);
}


int main(int argc, char* argv[])
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(9);
	vec.push_back(10);
	vec.push_back(15);
	vec.push_back(20);

	int val = 9;

	test_findVal_byloop(vec, val);
	test_findVal_byrecursion(vec, val);
	
	test_findRootOfVal(18, 6);
}