#define SEARCH_IN_ROTATED_SORTED_ARRAY
#ifdef SEARCH_IN_ROTATED_SORTED_ARRAY

#include <iostream>

int searchInRotatedSortedArray(int arr[], int val, int n)
{
	
	int pivot = -1;
	int low = 0, high = 0, mid = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			pivot = i;
			break;
		}
	}

	if ((arr[0] <= val) && (val <= arr[pivot]))
	{
		low = 0, high = pivot;
	}
	else if ((val >= arr[pivot + 1]) && (val <= arr[n - 1]))
	{
		low = pivot + 1, high = n - 1;
	}
	else
		return -1;

	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (arr[mid] == val)
			return mid;
		else if (arr[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}


int main(int argc, char* argv)
{
	int arr1[6] = { 3, 4, 5, 8, 1, 2 };
	int idx1 = searchInRotatedSortedArray(arr1, 7, 6);
	printf("the first index is: %d\n", idx1);

}

#endif