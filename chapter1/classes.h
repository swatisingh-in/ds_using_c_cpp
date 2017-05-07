#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

class RATIONAL{
	int num;
	int den;
	void reduce();
public:
	RATIONAL add(RATIONAL &);
	RATIONAL mul(RATIONAL &);
	RATIONAL div(RATIONAL &);
	void setrational(int, int);
	void print();
};

#endif  //CLASSES_H