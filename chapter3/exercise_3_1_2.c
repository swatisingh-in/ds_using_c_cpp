//Exercise 3.1.2

#include <stdio.h>

int succ(int a, int b)
{
	if (b == 0)
		return a;
	else
		return succ(++a, b-1);
}

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 12390;

	printf("sum of %d and %d is: %d\n", a, b, a+b);
	printf("sum of %d and %d is using recursion is: %d\n", a, b, succ(a, b));
	return 0;
}