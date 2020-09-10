#define QUICK_SORT
#ifdef QUICK_SORT

#include <iostream>
using namespace std;



int partition(int arr[], int p, int r)
{
	int* tmp_left = new int[r - p + 1]{ 0 };
	int* tmp_right = new int[r - p + 1]{ 0 };

	int pivot = arr[r];
	int idx_left = 0;
	int idx_right = 0;
	int q = 0;
	for (int i = p; i < r; i++)
	{
		if (arr[i] <= pivot)
		{
			tmp_left[idx_left++] = arr[i];
		}
		else
		{
			tmp_right[idx_right++] = arr[i];
		}
	}

	//copy tmp to arr;
	for (int i = 0; i < idx_left; i++)
	{
		arr[p + i] = tmp_left[i];
	}

	q = p + idx_left;
	arr[q] = pivot;
	
	for (int i = 0; i < idx_right; i++)
	{
		arr[p + idx_left + 1 + i] = tmp_right[i];
	}

	delete[] tmp_left;
	delete[] tmp_right;
	tmp_left = nullptr;
	tmp_right = nullptr;
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