#include "stack.h"
#include <string.h>
#include "math.h"

#define MAX_COL 80

int oper(int symb, int opnd1, int opnd2)
{
	switch(symb){
		case '+':
			return (opnd1 + opnd2);
			break;
		case '-':
			return (opnd1 - opnd2);
			break;
		case '*':
			return (opnd1 * opnd2);
			break;
		case '/':
			return (opnd1 / opnd2);
			break;
		case '$':
			return (pow(opnd1, opnd2));
			break;
		default:
			printf("Invalid operation\n");
			exit(1);
	}
}

int is_digit(char s)
{
	return (s >= '0' && s <= '9');
}

int eval(char str[])
{
	int opnd2, opnd1;
	STACK s;

	init_stack(&s);
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (is_digit(str[i])){
			push(&s, (str[i] - '0'));
		}
		else {
			opnd2 = pop(&s);
			opnd1 = pop(&s);
			int result = oper(str[i], opnd1, opnd2);
			push(&s, result);
		}
	}

	return pop(&s);
}

int main(int argc, char const *argv[])
{
	char str[MAX_COL];

	strncpy(str, "623+-382/+*2$3+", MAX_COL);

	printf("postfix expression is: %s\n", str);

	printf("Result: %d\n", eval(str));
	return 0;
}