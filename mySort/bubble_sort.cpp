//#define BUBBLE_SORT
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

	for (int j = 1; j < n; j++)
	{
		int swap_flag = false;
		for (int i = 0; i < n - j; i++)
		{
			if (sort_type == 0)
			{
				if (arr[i] > arr[i + 1])
				{
					int tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					swap_flag = true;
				}
			}
			else//sort_type == 1
			{
				if (arr[i] < arr[i + 1])
				{
					int tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					swap_flag = true;
				}
			}
		}

		if (swap_flag == false)//represents has sorted data
			break;
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
