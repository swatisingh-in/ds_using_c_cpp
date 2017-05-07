#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct{
	int top;
	char elem[MAX];
}STACK;

void init_stack(STACK *);
int is_empty(STACK *);
int stack_top(STACK *);
void push(STACK *, int i);
int pop(STACK *);
void print_stack(STACK *);

#endif // STACK_h