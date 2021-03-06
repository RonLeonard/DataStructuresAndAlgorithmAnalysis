#include <iostream>
#include "mySort.h"

using namespace sort_alg;

void printVec(vector<int>& vec)
{
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}




void insertSort_test(vector<int> vec)
{
	CMySort mySort;
	mySort.insertSort(vec, SMALL2LARGE);
	printVec(vec);
}


void mergeSort_test(vector<int> vec)
{
	CMySort mySort;
	mySort.mergeSort(vec, LARGE2SAMLL);
	printVec(vec);
}


void quickSort_test(vector<int> vec)
{
	CMySort mySort;
	mySort.quickSort(vec, SMALL2LARGE);
	printVec(vec);
}


void getKThElem_test(vector<int> vec, const int K)
{
	CMySort mySort;
	int val;
	val = mySort.getKThElem(vec, K);
	printf("The Kth Elem is : %d\n", val);
}

int main(int argc, char* argv[])
{
	vector<int> origin_datas;
	origin_datas.push_back(4);
	origin_datas.push_back(5);
	origin_datas.push_back(6);
	origin_datas.push_back(1);
	origin_datas.push_back(2);
	origin_datas.push_back(3);
	printf("test insert sort:\n");
	insertSort_test(origin_datas);
	printf("test merge sort:\n");
	mergeSort_test(origin_datas);
	printf("test quick sort:\n");
	quickSort_test(origin_datas);
	printf("test getKThElem sort:\n");
	getKThElem_test(origin_datas, 5);
}
