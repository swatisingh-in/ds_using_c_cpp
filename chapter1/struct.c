#include <stdio.h>
#include <string.h>

typedef struct name{
	char first[20];
	char midinit;
	char last[20];
}NAME;

int writename(NAME *sname)
{
	int count;
	for(int i = 0; i < 20 && sname->first[i] != '\0'; i++)
	{
		printf("%c", sname->first[i]);
		count++;
	}

	printf("%c", ' ');
	count++;

	if (sname->midinit != ' '){
		printf("%c%s", sname->midinit, ". ");
		count = count + 3;
	}

	for(int i = 0; i < 20 && sname->last[i] != '\0'; i++)
	{
		printf("%c", sname->last[i]);
		count++;
	}

	printf("\n");
	return count;
}

int main(int argc, char const *argv[])
{
	NAME sname;
	strcpy(sname.first, "Swati");
	sname.midinit = ' ';
	strcpy(sname.last, "Singh");

	printf("Count is: %d\n", writename(&sname));
	return 0;
}