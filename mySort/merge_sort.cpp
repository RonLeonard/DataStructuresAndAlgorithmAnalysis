//#define MERGE_SORT
#ifdef MERGE_SORT


#include <iostream>
using namespace std;


void merge_sort_m1(int arr[], int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r) / 2;
	merge_sort_m1(arr, p, q);
	merge_sort_m1(arr, q + 1, r);
	for (int i = q + 1; i <= r; i++)
	{
		int val = arr[i];
		int insert_pos = i;
  		for (int j = i - 1; j >= p; j--)
		{
			if (arr[j] > val)
			{
				arr[j + 1] = arr[j];
				insert_pos = j;
			}
			else
			{
				break;
			}
		}
		arr[insert_pos] = val;
	}
}


void merge_array(int arr[], int p, int q, int r)
{
	int *tmp;
	tmp = new int[r - p + 1];// (int*)malloc((r - p + 1) * sizeof(int));
	
	int i = p, j = q + 1;
	int idx = 0;
	while ((i <= q) && (j <= r))
	{
		if (arr[i] <= arr[j])
		{
			tmp[idx++] = arr[i++];
		}
		else
		{
			tmp[idx++] = arr[j++];
		}
	}
	
	int start = i;
	int end = q;
	if (j <= r)
	{
		start = j;
		end = r;
	}
	while (start <= end)
	{
		tmp[idx++] = arr[start++];
	}

	for (int m = p; m <= r; m++)
	{
		arr[m] = tmp[m - p];
	}
	//also can use memcpy implement copy operator.
	//memcpy((arr + p), tmp, (r - p + 1) * sizeof(int));
	delete[] tmp;
	tmp = nullptr;
}


void merge_sort_m2(int arr[], int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r) / 2;
	merge_sort_m2(arr, p, q);
	merge_sort_m2(arr, q + 1, r);
	merge_array(arr, p, q, r);
}



void mergeBySentry(int arr[], int p, int q, int r)
{
	int *leftArr = new int[q - p + 2];
	int *rightArr = new int[r - q + 1];
	for (int i = 0; i < q - p + 1; i++)
	{
		leftArr[i] = arr[p + i];
	}
	leftArr[q - p + 1] = INT_MAX;
	for (int j = 0; j < r - q; j++)
	{
		rightArr[j] = arr[q + 1 + j];
	}
	rightArr[r - q] = INT_MAX;

	int i = 0;
	int j = 0;
	int k = p;
	while (k <= r)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k++] = leftArr[i++];
		}
		else
		{
			arr[k++] = rightArr[j++];
		}
	}
}


void merge_sort_m3(int arr[], int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r) / 2;
	merge_sort_m2(arr, p, q);
	merge_sort_m2(arr, q + 1, r);
	mergeBySentry(arr, p, q, r);
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
	merge_sort_m3(a, 0, size - 1);
	print_arr(a, size);
	return 0;
}


#endif