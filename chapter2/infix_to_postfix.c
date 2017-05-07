#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int is_digit(char c)
{
	return (c >= '9' && c <= '0');
}

void convert_infix_to_postfix(char instr[], char poststr[])
{
	STACK s;
	init_stack(&s);

	int i = 0, j = 0;
	while(instr[i] != '\0'){
		if (is_digit(instr[i])){
			poststr[j++] = instr[i++];
			continue;
		}
		else {
			if (!is_empty(&s) && prec(instr[i], stack_top(&s))) {
				poststr[j++] = pop(&s);
			}
		}
		push(&s, instr[i]);
	}

	while(!is_empty(&s)){
		poststr[j++] = pop(&s);
	}
}

int main(int argc, char const *argv[])
{
	char instr[MAX] = "1 + 2 * 5";
	char poststr[MAX];

	printf("infix string is: %s\n", instr);

	convert_infix_to_postfix(instr, poststr);

	printf("postfix string is: %s\n", poststr);
	return 0;
}