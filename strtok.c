#include "lib.h"
int qStrtok(char *c)
{
	char *copy;

	char *tok;
	int i = 0, j = 0;

	for (; c[j]; j++)
		;

	copy = malloc(sizeof(char) * j);

	_strcpy(copy, c);
	if (c)
	{
		tok = strtok(copy, " ");
		if (tok)
		{
			while (tok)
			{
				i++; 
				tok = strtok(NULL, " ");
			}
		}
	}
	free(copy);
	return (i);
}

