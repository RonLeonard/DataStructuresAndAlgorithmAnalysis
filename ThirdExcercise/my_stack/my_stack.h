#ifndef _MY_STACK_H
#define _MY_STACK_H

#include <vector>


template <typename T> class CStack
{
public:
	CStack();
	CStack(const int& n_);
	~CStack();
	bool push(const T& val);
	bool pop(T& val);
private:
	T arr*;
	int n;
	int count;
};

#endif
