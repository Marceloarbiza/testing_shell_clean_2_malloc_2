#include "lib.h"

char **concPath(char **p, char *s)
{
	int i = 0, lenp = 0, lens = 0;
	char *tmp;

	lens = _strlen(s);

	for (; p[i]; i++)
	{
		lenp = _strlen(p[i]);
		lenp = lenp + lens;
		tmp = str_concat(p[i], s);

		p[i] = malloc(sizeof(char) * (lenp + 1));
		if(!p[i])
			return (NULL);
		
		_strcpy(p[i], tmp);
		str_concat(p[i], s);
		lenp = 0;
		free(tmp);
	}
	return(p);
}

