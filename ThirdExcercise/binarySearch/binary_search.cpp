#include <vector>

using namespace std;

int binSearch_m1(const vector<int> &ivec, int value)
{
	int size = ivec.size();
	int low = 0, high = size - 1;
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if (ivec.at(mid) == value)
			return mid;
		else if (ivec.at(mid) < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}


int binSearch_recursion(vector<int> ivec, int value, int low, int high)
{
	if (low > high)
		return -1;
	int mid = low + ((high - low) >> 1);
	if (ivec.at(mid) == value)
		return mid;
	else if (ivec.at(mid) < value)
		return binSearch_recursion(ivec, value, mid + 1, high);
	else
		return binSearch_recursion(ivec, value, low, mid - 1);
}


int binSearch_m2(vector<int> ivec, int value)
{
	return binSearch_recursion(ivec, value, 0, ivec.size() - 1);
}



int findTheFirstEqualValue(const vector<int>& ivec, int value)
{
	if (ivec.empty())
		return -1;
	int low = 0;
	int high = ivec.size() - 1;
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if (ivec.at(mid) > value)
		{
			high = mid - 1;
		}
		else if (ivec.at(mid) < value)
		{
			low = mid + 1;
		}
		else
		{
			if (mid == 0 || ivec.at(mid - 1) < value)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return -1;
}


int findTheLastEqualValue(const vector<int>& ivec, int value)
{
	if (ivec.empty())
		return -1;
	int low = 0;
	int n = ivec.size();
	int high = n - 1;
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if (ivec.at(mid) > value)
		{
			high = mid - 1;
		}
		else if (ivec.at(mid) < value)
		{
			low = mid + 1;
		}
		else
		{
			if ((mid == n - 1) || ivec.at(mid + 1) > value)
			{
				return mid;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
	return -1;
}


int findTheFirstBiggerOrEqualVal(const vector<int>& ivec, int value)
{
	if (ivec.empty())
	{
		return -1;
	}
	int low = 0;
	int n = ivec.size();
	int high = n - 1;
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if (ivec.at(mid) >= value)
		{
			if (mid == 0 || ivec.at(mid - 1) < value)
				return mid;
			else
				high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
}


int findTheLastSmallerOrEqualVal(const vector<int>& ivec, int value)
{
	if (ivec.empty())
	{
		return -1;
	}
	int low = 0;
	int n = ivec.size();
	int high = n - 1;
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if (ivec.at(mid) <= value)
		{
			if (mid == n - 1 || ivec.at(mid + 1) > value)
				return mid;
			else
				low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
}


int main(int argc, char* argv[])
{
	vector<int> ivec;
	for (int i = 3; i < 6; i++)
	{
		ivec.push_back(i);
	}
	for (int i = 5; i < 10; i++)
	{
		ivec.push_back(i);
	}
	for (auto i : ivec)
	{
		printf("%d ", i);
	}
	printf("\n");
	int val = 5;
	/*int idx = binSearch_m2(ivec, val);
	if (idx < 0)
		printf("%d no found\n", val);
	else
		printf("ivec[%d] = %d\n", idx, ivec[idx]);*/
	int idx = findTheFirstEqualValue(ivec, val);
	if (idx < 0)
		printf("%d no found\n", val);
	else
		printf("first ivec[%d] = %d\n", idx, ivec[idx]);
	idx = findTheLastEqualValue(ivec, val);
	if (idx < 0)
		printf("%d no found\n", val);
	else
		printf("the last ivec[%d] = %d\n", idx, ivec[idx]);
	idx = findTheFirstBiggerOrEqualVal(ivec, val);
	if (idx < 0)
		printf("%d no found\n", val);
	else
		printf("the last ivec[%d] = %d\n", idx, ivec[idx]);
	idx = findTheLastSmallerOrEqualVal(ivec, val);
	if (idx < 0)
		printf("%d no found\n", val);
	else
		printf("the last ivec[%d] = %d\n", idx, ivec[idx]);
	return 0;
}