//#define BISEARCH
#ifdef BISEARCH


#include <iostream>
using namespace std;

/**********
*function description: this method use ciculation method
*
***********/
int bisearch_c0(int arr[], int low, int high, int val)
{
	while (low <= high)
	{
		//overflow probably
		//int mid = (low + high) / 2;

		//int mid = low + (high - low) / 2;
		//more effective
		int mid = low + ((high - low) >> 1);
		if (arr[mid] == val)
		{
			return mid;
		}
		else if (arr[mid] < val)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}


/**********
*function description: this method use ciculation method
*
***********/
int bisearch_c1(int arr[], int low, int high, int val)
{
	if (low > high)
	{
		return -1;
	}
	
	int mid = low + ((high - low) >> 1);
	if (arr[mid] == val)
		return mid;
	else if (arr[mid] < val)
		low = mid + 1;  
	else
		high = mid - 1;
	return bisearch_c1(arr, low, high, val);
}


/*************
*
*method_type: 0: cicular, 1: recursion
***************/
int bisearch(int arr[], int n, int val, int method_type)
{
	int idx = -9999;
	if (method_type == 0) //cicular
		idx = bisearch_c0(arr, 0, n - 1, val);
	else
		idx = bisearch_c1(arr, 0, n - 1, val);
	return idx;
}


int main(int argc, char** argv)
{
	int arr[6] = { 1, 3, 4, 19, 20, 30 };
	int find_val = 20;
	int idx = bisearch(arr, 6, find_val, 0);
	cout << "idx = " << idx << endl;
}

#endif