//#define FIND_THE_FIRST_BIGGEROREQUAL_SPECIFIED_VAL
#ifdef FIND_THE_FIRST_BIGGEROREQUAL_SPECIFIED_VAL

#include <iostream>

/*************
funciton descryption:¡¡
find the first index that bigger or equal specified val
*************/


int findTheFirstBiggerOrEqualSpecifiedVal(int arr[], int val, int n)
{
	int low = 0, high = n - 1;
	int mid = -1;

	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (arr[mid] >= val)
		{
			if ((mid != 0) && (arr[mid - 1] >= val))
				high = mid - 1;
			else
				return mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}



int main(int argc, char* argv)
{
	int arr1[6] = { 1, 3, 4, 5, 8, 10 };
	int idx1 = findTheFirstBiggerOrEqualSpecifiedVal(arr1, 1, 6);
	printf("the first index is: %d\n", idx1);

	int arr2[6] = { 1, 2, 3, 5, 7, 8 };
	int idx2 = findTheFirstBiggerOrEqualSpecifiedVal(arr2, 5, 6);
	printf("the first index is: %d\n", idx2);
}


#endif