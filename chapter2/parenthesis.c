#include "stack.h"

int match_pair(char c1, char c2){
	if ((c1 == '(') && (c2 == ')'))
		return TRUE;
	else if ((c1 == '[') && (c2 == ']'))
		return TRUE;
	else if ((c1 == '{') && (c2 == '}'))
		return TRUE;
	else
		return FALSE;
}

int main(int argc, char const *argv[])
{
	char str[] = "[((([a + b]))) - (c * d) / 5  * (a + b)]";
	STACK s;
	int valid = TRUE;

	init_stack(&s);

	for(int i = 0; str[i] != '\0'; i++){
		if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
			push(&s, str[i]);

		if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) {
			if (is_empty(&s)) {
				valid = FALSE;
			}
			else {
				char c = pop(&s);

				if (!match_pair(c, str[i]))
					valid = FALSE;
			}			
		}

	}

	if (!is_empty(&s))
		valid = FALSE;

	if (valid == TRUE)
		printf("Matching pair\n");
	else
		printf("Not Matching\n");
	return 0;
}