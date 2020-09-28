//#define FIND_THE_LAST_SPECIFIED_VAL
#ifdef FIND_THE_LAST_SPECIFIED_VAL

#include <iostream>

int findTheLastSpecifiedVal(int arr[], int val, int n)
{
	int low = 0, high = n - 1;
	int mid = -1;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (arr[mid] == val)
		{
			if ((mid != n - 1) && (arr[mid + 1] == val))
				low = mid + 1;
			else
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


int main(int argc, char* argv)
{
	int arr1[6] = { 1, 3, 4, 5, 8, 8 };
	int idx1 = findTheLastSpecifiedVal(arr1, 8, 6);
	printf("the first index is: %d\n", idx1);

	int arr2[6] = { 1, 4, 4, 4, 7, 8 };
	int idx2 = findTheLastSpecifiedVal(arr2, 3, 6);
	printf("the first index is: %d\n", idx2);
}


#endif