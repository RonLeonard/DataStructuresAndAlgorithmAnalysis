//#define INSERT_SORT
#ifdef INSERT_SORT

#include <iostream>
using namespace std;



/****************
*arr[] : is the sequence to be sorted
*n : the number of arr[]
*sort_type:
*		    == 0: sorted from samll to large
*		    == 1: sorted from large to small
******************/

/*********this method is compared from head to tail************/
void insert_sort_m1(int arr[], int n, int sort_type)
{
	if (n <= 1)
	{
		return;
	}
	for (int j = 1; j < n; j++)
	{
		int insert_pos = 0;
		int insert_val = arr[j];
		bool moveFlag = false;
		for (int i = 0; i < j; i++)
		{
			if (sort_type == 0)
			{
				if (arr[i] > insert_val)
				{
					insert_pos = i;
					moveFlag = true;
					break;
				}
			}
			else
			{
				if (arr[i] < insert_val)
				{
					insert_pos = i;
					moveFlag = true;
					break;
				}
			}
		}
		if (moveFlag == true)
		{
			for (int i = j - 1; i >= insert_pos; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[insert_pos] = insert_val;
		}
	}
}



/*********this method is compared from tail to head************/
void insert_sort_m2(int arr[], int n, int sort_type)
{
	for (int j = 1; j < n; j++)
	{
		int value = arr[j];
		int i = j - 1;
		for (; i >= 0; i--)
		{
			if (sort_type == 0)//sorted from small to large
			{
				if (arr[i] > value)
				{
					arr[i + 1] = arr[i];
				}
				else
				{
					break;
				}
			}
			else
			{
				if (arr[i] < value)//sorted from large to small
				{
					arr[i + 1] = arr[i];
				}
				else
				{
					break;
				}
			}
		}
		arr[i + 1] = value;
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
	print_arr(a, 6);
	insert_sort_m2(a, 6, 0);
	print_arr(a, 6);


	return 0;
}

#endif