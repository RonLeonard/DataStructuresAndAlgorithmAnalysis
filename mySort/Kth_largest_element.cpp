#define kTH_LARGEST_ELEMENT
#ifdef kTH_LARGEST_ELEMENT

#include <iostream>
using namespace std;


void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


int partition(int arr[], int p, int r)
{
	int pivot = arr[r];
	int i = p;
	for (int j = p; j < r; j++)
	{
		if (arr[j] >= pivot)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}


int find_Kth_largest_elem_c(int arr[], int p, int r, int Kth)
{
	if (p >= r)
	{
		return arr[p];
	}
	int q = partition(arr, p, r);
	if (q + 1 == Kth)
	{
		return arr[q];
	}
	else if (q + 1 < Kth)
	{
		find_Kth_largest_elem_c(arr, q + 1, r, Kth);
	}
	else
	{
		find_Kth_largest_elem_c(arr, p, q - 1, Kth);
	}
}


int find_Kth_largest_elem(int arr[], int n, int Kth)
{
	if (n < Kth)
	{
		std::cout << "the size of arr smaller than Kth." << std::endl;
		return -1;
	}
	return find_Kth_largest_elem_c(arr, 0, n - 1, Kth);
}


void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	const int size = 6;
	int a[size];
	for (int i = 0; i < size; i++)
		a[i] = rand() % 100;
	print_arr(a, size);
	int elem = find_Kth_largest_elem(a, size, 5);
	std::cout << "the Kth largest elem is:¡¡" << elem << endl;
}

#endif