//#define PERFORMANCE_TEST
#ifdef PERFORMANCE_TEST


#include <iostream>
#include <chrono>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

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

const int n = 200;
int randArr[n];

int main(int argc, char **argv)
{

	for (int i = 0; i < n; i++)
		randArr[i] = rand() % 100;
	auto start_1 = high_resolution_clock::now();
	bubble_sort(randArr, n, 0);
	auto end_1 = high_resolution_clock::now();
	cout << duration_cast<nanoseconds>(end_1 - start_1).count() << "ns\n";
	cout << endl;

	auto start_2 = high_resolution_clock::now();
	insert_sort_m2(randArr, n, 0);
	auto end_2 = high_resolution_clock::now();
	cout << duration_cast<nanoseconds>(end_2 - start_2).count() << "ns\n";
	cout << endl;
}


#endif