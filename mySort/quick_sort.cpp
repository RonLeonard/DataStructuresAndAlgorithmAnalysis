#define QUICK_SORT
#ifdef QUICK_SORT

#include <iostream>
using namespace std;


/***********************
*
*
*this method is not in-place sort
***********************/
int partition_m1(int arr[], int p, int r)
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



/*******************
*
*
*in place method
********************/
int partition_m2(int arr[], int p, int r)
{
	int pivot = arr[r];
	int i;
	for (i = p; i < r; i++)
	{
		int min_val = arr[i];
		int min_idx = i;
		for (int j = i + 1; j < r; j++)
		{
			if (arr[j] < min_val)
			{
				min_val = arr[j];
				min_idx = j;
			}
		}
		if (min_val <= pivot)
		{
			int tmp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = tmp;
		}
		else
		{
			break;
		}
	}
	arr[i] = pivot;
	arr[r] = arr[i];
	return i;
}


void quick_sort_imp(int arr[], int p, int r, bool in_place_flag)
{
	if (p >= r)
		return;
	int q;
	if (in_place_flag)
		q = partition_m2(arr, p, r);
	else
		q = partition_m1(arr, p, r);
	quick_sort_imp(arr, p, q - 1, in_place_flag);
	quick_sort_imp(arr, q + 1, r, in_place_flag);
}


/*******************
*params:
*	n: the size of arr.
*******************/
void quick_sort(int arr[], int n, bool in_place_flag)
{
	quick_sort_imp(arr, 0, n - 1, in_place_flag);
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
	quick_sort(a, size, 1);
	print_arr(a, size);
	return 0;
}

#endif