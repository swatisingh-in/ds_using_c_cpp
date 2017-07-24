//Find the maximum element of the array, recursive and iterative approach

#include <stdio.h>

int iterative(int arr[], int len)
{
	int i, max = arr[0];
	for(i = 0; i < len; i++){
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}

int recursive(int arr[], int low, int high)
{
	static int max;

	if (low == high){
		if (arr[low] > max)
			max = arr[low];
		return max;
	}

	if (low > high)
		return max;

	if (arr[low] > max)
		max = arr[low];

	if (arr[high] > max)
		max = arr[high];

	return recursive(arr, low + 1, high - 1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 4, 9, 2, 8, 1500, 12000};

	int len = sizeof(arr)/sizeof(arr[0]);

	printf("Maximum element of array is: iterative: %d\n", iterative(arr, len));
	printf("Maximum element of array is: recursive: %d\n", recursive(arr, 0, len-1));
	return 0;
}