#define QUICK_SORT
#ifdef QUICK_SORT

#include <iostream>
using namespace std;



int partition(int arr[], int p, int r)
{
	int* tmp = new int[r - p + 1];
	int val = arr[r];
	int i = p;
	while ((i <= r) && (arr[i] <= val))
	{
		tmp[i - p] = arr[i++];
	}
	int q = i;
	arr[q] = val;
	i++;
	while ((i <= r) && (arr[i] > val))
	{
		tmp[i - p] = arr[i++];
	}
	for (int i = p; i <= r; i++)
	{
		arr[i] = tmp[i - p];
	}
	delete[] tmp;
	tmp = nullptr;
	return q;
}


void quick_sort_imp(int arr[], int p, int r)
{
	if (p >= r)
		return;
	int q = partition(arr, p, r);
	quick_sort_imp(arr, p, q - 1);
	quick_sort_imp(arr, q + 1, r);
}


/*******************
*params:
*	n: the size of arr.
*******************/
void quick_sort(int arr[], int n)
{
	quick_sort_imp(arr, 0, n - 1);
}



void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



int main(int argc, char** argv)
{

	const int size = 10;
	int a[size];
	for (int i = 0; i < size; i++)
		a[i] = rand() % 100;
	print_arr(a, size);
	quick_sort(a, size);
	print_arr(a, size);
	return 0;
}

#endif