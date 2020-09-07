//#define SELECT_SORT
#ifdef SELECT_SORT


#include <iostream>
using namespace std;


void select_sort(int arr[], int n, int sort_type)
{
	if (n <= 1)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int val = arr[i];
		int pos = i;
		for (int j = i; j < n; j++)
		{
			if (sort_type == 0)
			{
				if (arr[j] < val)
				{
					val = arr[j];
					pos = j;
				}
			}
			else
			{
				if (arr[j] > val)
				{
					val = arr[j];
					pos = j;
				}
			}
		}
		int tmp = arr[i];
		arr[i] = val;
		arr[pos] = tmp;
	}
	return;
}


void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}


int main(int argc, char** argv)
{
	int a[6] = { 4, 5, 6, 3, 2, 1 };
	print_arr(a, 6);
	select_sort(a, 6, 0);
	print_arr(a, 6);


	return 0;
}


#endif