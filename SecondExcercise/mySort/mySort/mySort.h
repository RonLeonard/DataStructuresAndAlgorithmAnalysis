#ifndef MYSORT_H_
#define MYSORT_H_

#include <vector>

using namespace std;
namespace sort_alg
{
#define INTEGER_MAXIMUM 9999
#define INTEGER_MINIMUM -9999
	enum sortTepe
	{
		SMALL2LARGE = 0,
		LARGE2SAMLL,
	};


	class CMySort
	{
	public:
		CMySort();
		~CMySort();
		void insertSort(vector<int>& vec, const int sortType);
		void mergeSort(vector<int>& vec, const int sortType);
		void quickSort(vector<int>& vec, const int sortType);
	private:
		void mergeSort_imp(vector<int>& vec, const int sortType, int p, int r);
		void merge(vector<int>& vec, const int sortType, int p, int q, int r);
		void mergeBySentry(vector<int>& vec, const int sortType, int p, int q, int r);
		//
		void quickSort_imp(vector<int>& vec, const int sortType, int p, int r);
		int partition(vector<int>& vec, const int sortType, int p, int r);

		void swap(int& a, int& b);
	};
}
#endif
