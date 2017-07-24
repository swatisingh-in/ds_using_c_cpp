//Calculate average of array elements, recursive and iterative approach

#include <stdio.h>

double iterative_sum(int arr[], int len)
{
	int i;
	double sum = 0;
	for(i = 0; i < len; i++)
		sum = sum + arr[i];

	return sum;
}

double recursive_sum(int arr[], int low, int high)
{
	static double sum = 0;

	if (low == high)
		return sum + arr[low];

	if (low > high)
		return sum;

	sum = sum + arr[low] + arr[high];
	return recursive_sum(arr, low + 1, high - 1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 4, 9, 2, 8, 10, 23};

	int len = sizeof(arr)/sizeof(arr[0]);


	printf("Average of array elements iterative: %f\n", iterative_sum(arr, len)/len);
	printf("Average of array elements recursive: %f\n", recursive_sum(arr, 0, len-1)/len);
	return 0;
}