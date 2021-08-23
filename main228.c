#include "lib.h"

int main(void)
{
	
	char *buf;
	size_t bufsize = 1024;
	int chara;
	char **doub;
	char *simp;
	char **simpD;
	char *slash;
	
	while (1)
	{
		if (isatty(0))
			write(1,"$ ",2);

		buf = malloc(sizeof(char *) * bufsize);
		if (!buf)
			return (0);
		
		chara = getline(&buf, &bufsize, stdin);
		
		if (chara == -1)
			return (-1);
		
		if((buf[chara - 1]) == '\n')
			buf[chara - 1] = 0;
		
		doub = strD2(buf);
		
		simp = compEnv("PATH");



		simpD = strD2Path(simp);

		slash = str_concat("/", doub[0]);
		
		concPath(simpD, slash);

		executen(simpD, doub);
		
	}
	return (0);
}
