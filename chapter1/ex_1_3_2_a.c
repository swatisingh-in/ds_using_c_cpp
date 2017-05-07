#include <stdio.h>

typedef struct 
{
	int whole;
	int dec;
} REAL;

void convert_to_struct(REAL *r1, float num)
{
	char buf[128];
	snprintf(buf, 128, "%f", num);

	printf("%s\n", buf);
	int l = 0;
	int r = 0, i;

	for(i = 0; buf[i] != '.' && buf[i] != '\0'; i++){
		l = l * 10 + (buf[i] - '0');
	}

	for(int j = i + 1; buf[j] != '\0'; j++)
		r = r * 10 + (buf[j] - '0');

	printf("%d:%d\n", l, r);
	r1->whole = l;
	r1->dec = r;
}

int main(int argc, char const *argv[])
{
	REAL r1;
	float real;

	printf("Enter a real number\n");
	scanf("%f", &real);

	printf("The real number is: %f\n", real);

	convert_to_struct(&r1, real);

	printf("%d:%d\n", r1.whole, r1.dec);
	return 0;
}