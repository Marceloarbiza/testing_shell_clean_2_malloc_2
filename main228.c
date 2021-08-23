#include "lib.h"

int main(void)
{
	
	char *buf;
	size_t bufsize = 1024, chara;
/*	int q = 0;*/
	char **doub;
	char *simp;
	char **simpD;
	char *slash;
	
/*	buf = malloc(sizeof(char) * bufsize);
	if (!buf)
		return (0);
*/

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
	/*	int t = _strcmp(buf, "EOF");
		
		if (t == 0)
			return (-1);
	*/

/*		q = qStrtok(buf);*/
		
		doub = strD2(buf);
		
	/*	for (int h = 0; h < q; h++)
			printf("doub[%d]: %s\n", h, doub[h]);
	*/
		
		simp = compEnv("PATH");



		simpD = strD2Path(simp);
	/*
		for (int gg = 0; simpD[gg]; gg++)
			printf("DP [%d]: %s\n", gg, simpD[gg]);
	*/	

		slash = str_concat("/", doub[0]);
		
		concPath(simpD, slash);


	/*	for (int kk = 0; simpD[kk]; kk++)
		{
			printf("simpD[%d]: %s\n", kk, simpD[kk]);
		} */
		

		executen(simpD, doub);

		
		
	}
	return (0);
}
