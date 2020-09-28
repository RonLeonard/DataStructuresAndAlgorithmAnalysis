//#define FIND_THE_FIRST_SPECIFIED_VAL
#ifdef FIND_THE_FIRST_SPECIFIED_VAL
#include <iostream>


int findTheFirstSpecifiedVal(int arr[], int val, int n)
{
	int low = 0, high = n - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (arr[mid] == val)
		{
		#if 0//not simplified
			if (mid == 0)//means the index of mid is wanted.
			{
				return mid;
			}
			else
			{
				while (1)
				{
					if ((arr[mid - 1] == arr[mid]) && (mid != 0))
					{
						mid -= 1;
					}
					else
					{
						return mid;
					}
				}
			}
		#endif
			if ((mid == 0) || (arr[mid - 1] != val))
				return mid;
			else
				high = mid - 1;

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
	int arr1[6] = {1, 3, 4, 5, 8, 8};
	int idx1 = findTheFirstSpecifiedVal(arr1, 8, 6);
	printf("the first index is: %d\n", idx1);

	int arr2[6] = { 1, 4, 4, 4, 7, 8 };
	int idx2 = findTheFirstSpecifiedVal(arr2, 4, 6);
	printf("the first index is: %d\n", idx2);
}


#endif
