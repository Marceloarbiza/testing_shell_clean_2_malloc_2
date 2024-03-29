#include "lib.h"

char **strD2(char *c)
{
	char **strD;
	char *copy;
	char *tok;
	int j = 0, k = 0, q = 0, len = 0;

	for (; c[j]; j++)
		;

	copy = malloc(sizeof(char) * (j + 1));

	_strcpy(copy, c);

	copy[j] = '\0';

	if (c)
	{
		q = qStrtok(c);

		strD = malloc(sizeof(char *) * (q + 1));
		if(!strD)
			return (NULL);

		strD[q] = NULL;

		tok = strtok(copy, " ");
		if (tok)
		{
			while (tok)
			{
				len = _strlen(tok);

				strD[k] = malloc(sizeof(char) * (len + 1));
				if (!strD)
					return (NULL);

				_strcpy(strD[k], tok);

				tok = strtok(NULL, " ");
				k++;
			}

			strD[k] = '\0';
		}
	}
	free(copy);
	return (strD);
}

