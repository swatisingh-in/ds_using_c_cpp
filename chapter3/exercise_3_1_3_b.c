//Find the minimum element of the array, recursive and iterative approach

#include <stdio.h>

int iterative(int arr[], int len)
{
	int i, min = arr[0];
	for(i = 1; i < len; i++){
		if (arr[i] < min)
			min = arr[i];
	}

	return min;
}

int recursive(int arr[], int low, int high)
{
	static int min = 9999999;

	if (low == high){
		if (arr[low] < min)
			min = arr[low];
		return min;
	}

	if (low > high)
		return min;

	if (arr[low] < min)
		min = arr[low];

	if (arr[high] < min)
		min = arr[high];

	return recursive(arr, low + 1, high - 1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 4, 9, 2, 8, 1500, 12000};

	int len = sizeof(arr)/sizeof(arr[0]);

	printf("minimum element of array is: iterative: %d\n", iterative(arr, len));
	printf("minimum element of array is: recursive: %d\n", recursive(arr, 0, len-1));
	return 0;
}