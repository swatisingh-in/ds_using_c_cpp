//Calculate product of array elements, recursive and iterative approach

#include <stdio.h>

int iterative_product(int arr[], int len)
{
	int i, product = 1;
	for(i = 0; i < len; i++)
		product = product * arr[i];

	return product;
}

int recursive_product(int arr[], int low, int high)
{
	static int product = 1;

	if (low == high)
		return product * arr[low];

	if (low > high)
		return product;

	product = product * arr[low] * arr[high];
	return recursive_product(arr, low + 1, high - 1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 4, 9, 2, 8, 4, 0};

	int len = sizeof(arr)/sizeof(arr[0]);

	printf("product of array elements iterative: %d\n", iterative_product(arr, len));
	printf("product of array elements recursive: %d\n", recursive_product(arr, 0, len-1));
	return 0;
}