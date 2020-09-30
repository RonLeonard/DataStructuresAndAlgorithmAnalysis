//#define FIND_THE_SMALLER_SMALLEROREQUAL_SPECIFIED_VAL
#ifdef FIND_THE_SMALLER_SMALLEROREQUAL_SPECIFIED_VAL

#include <iostream>


int find_the_last_smaller_or_equal_specified_val(
	int arr[], int val, int n)
{
	if (n <= 0)
		return -1;

	int low = 0, high = n - 1;
	int mid = -1;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (arr[mid] <= val)
		{
			if ((mid != n - 1) && (arr[mid + 1] <= val))
			{
				low = mid + 1;
			}
			else
				return mid;
		}
		else
			high = mid - 1;
	}
	return -1;
}



int main(int argc, char* argv)
{
	int arr1[6] = { 1, 1, 4, 5, 8, 10 };
	int idx1 = find_the_last_smaller_or_equal_specified_val(arr1, 0, 6);
	printf("the first index is: %d\n", idx1);

	int arr2[6] = { 1, 2, 3, 5, 7, 8 };
	int idx2 = find_the_last_smaller_or_equal_specified_val(arr2, 5, 6);
	printf("the first index is: %d\n", idx2);
}


#endif