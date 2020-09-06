#define BUBBLE_SORT
#ifdef BUBBLE_SORT

#include <iostream>

using namespace std;

/****************
*arr[] : is the sequence to be sorted
*n : the number of arr[]
*sort_type:
*		    == 0: sorted from samll to large
*		    == 1: sorted from large to small
******************/
void bubble_sort(int arr[], int n, bool sort_type)
{
	if (sort_type == 0)
	{
		for (int j = 1; j < n; j++)
		{
			for (int i = 0; i < n - j; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					int tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
				}
			}
		}
	}
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
	bubble_sort(a, 6, 0);
	print_arr(a, 6);
	
	return 0;
}


#endif
