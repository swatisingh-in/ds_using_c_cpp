#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
	int num;
	int den;
}RATIONAL;

void reduce(RATIONAL *r1, RATIONAL *ret1)
{
	int a, b;

	if (r1->num > r1->den) {
		a = r1->num;
		b = r1->den;
	}
	else {
		a = r1->den;
		b = r1->num;
	}

	while(b != 0){
		int rem = a % b;
		a = b;
		b = rem;
	}

	ret1->num = r1->num / a;
	ret1->den = r1->den / a;

	return;
}

int is_equal(RATIONAL *r1, RATIONAL *r2)
{
	RATIONAL ret1, ret2;

	reduce(r1, &ret1);
	printf("%d:%d\n", ret1.num, ret1.den);

	reduce(r2, &ret2);
	printf("%d:%d\n", ret2.num, ret2.den);	

	if ((ret1.num == ret2.num) && (ret1.den == ret2.den))
		return TRUE;
	else
		return FALSE;
}

void mul(RATIONAL *r1, RATIONAL *r2, RATIONAL *result)
{
	result->num = r1->num * r2->num;
	result->den = r1->den * r2->den;

	reduce(result, result);
}

int main(int argc, char const *argv[])
{
	RATIONAL r1, r2;

	r1.num = 1;
	r1.den = 2;

	r2.num = 59;
	r2.den = 126;

	if (is_equal(&r1, &r2) == TRUE)
		printf("Both are equal\n");
	else
		printf("Both rational numbers are not equal\n");

	RATIONAL result;

	mul(&r1, &r2, &result);

	printf("Multiplication is: %d:%d\n", result.num, result.den);

	return 0;
}