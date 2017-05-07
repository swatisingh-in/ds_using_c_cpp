#include "classes.h"

using namespace std;

void RATIONAL::setrational(int a, int b)
{
	num = a;
	den = b;

	reduce();
}

void RATIONAL::print()
{
	cout << num << "/" << den << endl;
}

void RATIONAL::reduce()
{
	int a, b;
	if (num > den) {
		a = num;
		b = den;
	}
	else {
		a = den;
		b = num;
	}

	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}

	num = num/a;
	den = den/a;

}

RATIONAL RATIONAL::add(RATIONAL &obj2)
{
	cout << "add" << endl;
	RATIONAL result;

	result.num = (num * obj2.den) + (den * obj2.num);
	result.den = den * obj2.den;

	result.reduce();

	return result;

}

RATIONAL RATIONAL::mul(RATIONAL &obj2)
{
	cout << "mul" << endl;
	RATIONAL result;

	result.num = num * obj2.num;
	result.den = den * obj2.den;

	result.reduce();

	return result;
}

RATIONAL RATIONAL::div(RATIONAL &obj2)
{
	cout << "div" << endl;

	RATIONAL result;

	result.num = num * obj2.den;
	result.den = den * obj2.num;

	result.reduce();

	return result;
}