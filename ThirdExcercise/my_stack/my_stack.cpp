#include <stdio.h>
#include "my_stack.h"



template<typename T> CStack<T>::CStack() : n(10), count(0)
{
	arr = new T[n];
	if (arr == nullptr)
	{
		printf("new arr failed");
	}
}


template<typename T> CStack<T>::CStack(const int& n_) : n(n_), count(0)
{
	arr = new T[n];
	if (arr == nullptr)
	{
		printf("new arr failed");
	}
}


template<typename T> CStack<T>::~CStack()
{
	count = 0;
	n = 0;
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}


template<typename T> bool CStack<T>::push(const T& val)
{
	if (count >= n)
		return false;
	arr[count] = val;
	count++;
	return true;
}


template<typename T> bool CStack<T>::pop(T& val)
{
	if (count <= 0)
		return false;
	count--;
	return arr[count];
}