#include "stack.h"

void init_stack(STACK *s)
{
	s->top = -1;
}

int is_empty(STACK *s)
{
	if (s->top == -1)
		return TRUE;
	else
		return FALSE;
}

int stack_top(STACK *s)
{
	if (is_empty(s)){
		printf("Stack is empty\n");
		exit(1);
	}
	return s->elem[s->top];
}

void push(STACK *s, int i)
{
	if (s->top == MAX-1) {
		printf("Overflow\n");
		exit(1);
	}

	s->elem[++s->top] = i;
}


int pop(STACK *s)
{
	if (is_empty(s)){
		printf("Underflow\n");
		exit(1);
	}
	return s->elem[s->top--];
}

void print_stack(STACK *s)
{
	printf("Printing Stack\n");
	for(int i = s->top; i >= 0; i--)
		printf("%d->", s->elem[i]);

	printf("\n");
}