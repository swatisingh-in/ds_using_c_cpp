#include "classes.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//Input num1 den1 num2 den2 op
	RATIONAL obj1;
	RATIONAL obj2;
	RATIONAL result;

	if (argc < 6){
		printf("Invalid input\n");
		return -1;
	}

	obj1.setrational(atoi(argv[1]), atoi(argv[2]));
	obj1.print();

	obj2.setrational(atoi(argv[3]), atoi(argv[4]));
	obj2.print();

	char c = argv[5][0];
	cout << c << endl;

	switch(c){
		case '+':
			result = obj1.add(obj2);
			result.print();
			break;
		case 'x':
			result = obj1.mul(obj2);
			result.print();
			break;
		case '/':
			result = obj1.div(obj2);
			result.print();
			break;
		default:
			cout << "Invalid Operand" << endl;
			break;
	}

	return 0;
}