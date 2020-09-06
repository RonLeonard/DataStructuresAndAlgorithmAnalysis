#define MERGE_SORT
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
	tmp = (int*)malloc((r - p + 1) * sizeof(int));
	
	int i = p, j = q + 1;
	int idx = 0;
	while ((i <= q) && (j <= r))
	{
		if (arr[i] <= arr[j])
		{
			tmp[idx] = arr[i];
			i++;
		}
		else
		{
			tmp[idx] = arr[j];
			j++;
		}
		idx++;
	}
	
	while (i <= q)
	{
		tmp[idx] = arr[i];
		i++;
		idx++;
	}

	while (j <= r)
	{
		tmp[idx] = arr[j];
		j++;
		idx++;
	}

	for (int m = p; m <= r; m++)
	{
		arr[m] = tmp[m - p];
	}

	if (tmp != nullptr)
	{
		free(tmp);
	}
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
	const int size = 7;
	int a[size];
	for (int i = 0; i < size; i++)
		a[i] = rand() % 100;
	print_arr(a, size);
	merge_sort_m2(a, 0, size - 1);
	print_arr(a, size);
	return 0;
}


#endif