#include <stdio.h>
#include <stdlib.h>

unsigned long int fact(unsigned long int num)
{
	if (num == 0)
		return 1;

	return num * fact(num - 1);
}

int main(int argc, char const *argv[])
{
	if (argc < 2){
		printf("Usage: %s number\n", argv[0]);
		return -1;
	}

	unsigned long int num = atol(argv[1]);

	printf("Number is: %lu\n", num);

	printf("fact is: %lu\n", fact(num));
	return 0;
}