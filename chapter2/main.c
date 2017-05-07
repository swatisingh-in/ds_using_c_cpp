#include "stack.h"

int main(int argc, char const *argv[])
{
	STACK s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	print_stack(&s);

	printf("%d\n", pop(&s));
	print_stack(&s);

	printf("Stack top is: %d\n", stack_top(&s));

	return 0;
}