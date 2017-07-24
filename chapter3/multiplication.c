//Calculate a * b using recursion
//Iterative algorithm to calculate a * b using addition

#include <stdio.h>

int mult_recursion(int a, int b)
{
	if (b == 0)
		return 0;

	if (b == 1)
		return a;
	else
		return a + mult_recursion(a, b-1);
}

int mult_iterative(int a, int b)
{
	int sum = 0;
	for (int i = 0; i < b; i++)
		sum += a;

	return sum;
}

int main(int argc, char const *argv[])
{
	int a = 60;
	int b = 1000;

	printf("Multiplication using recursion of %d and %d is: %d\n", a, b, mult_recursion(a, b));
	printf("Multiplication using Iteration of %d and %d is: %d\n", a, b, mult_iterative(a, b));
	return 0;
}