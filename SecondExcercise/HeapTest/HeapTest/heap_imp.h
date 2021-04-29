#ifndef HEAP_IMP_H
#define HEAP_IMP_H
#include <vector>

using namespace std;
class CBigTopHeap
{
public:
	CBigTopHeap();
	~CBigTopHeap();
	void insertElem(const int &data);
	void deleteTopElem();

private:
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

private:
	vector<int> ivec;

};


#endif