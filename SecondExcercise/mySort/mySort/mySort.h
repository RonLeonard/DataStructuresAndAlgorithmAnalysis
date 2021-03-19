#ifndef MYSORT_H_
#define MYSORT_H_

#include <vector>

using namespace std;
namespace sort_alg
{
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
	private:
		void mergeSort_imp(vector<int>& vec, const int sortType, int p, int r);
		void merge(vector<int>& vec, const int sortType, int p, int q, int r);
	};
}
#endif
