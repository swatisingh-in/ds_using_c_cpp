//Calculate sum of array elements, recursive and iterative approach

#include <stdio.h>

int iterative_sum(int arr[], int len)
{
	int i, sum = 0;
	for(i = 0; i < len; i++)
		sum = sum + arr[i];

	return sum;
}

int recursive_sum(int arr[], int low, int high)
{
	static int sum = 0;

	if (low == high)
		return sum + arr[low];

	if (low > high)
		return sum;

	sum = sum + arr[low] + arr[high];
	return recursive_sum(arr, low + 1, high - 1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 4, 9, 2, 8};

	int len = sizeof(arr)/sizeof(arr[0]);

	printf("Sum of array elements iterative: %d\n", iterative_sum(arr, len));
	printf("Sum of array elements recursive: %d\n", recursive_sum(arr, 0, len-1));
	return 0;
}