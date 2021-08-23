#include "lib.h"


int executen(char **d, char **a) 
{
	int i = 0, success = 0;
	pid_t pid = 0;
	int status;

	pid = fork();

	if (pid == 0) {
		for (i = 0; d[i]; i++)
		{
			success = execve(d[i], a, NULL);
		}

		if (success == -1)
			exit(98);
	}
		wait(&status);
   		printf("Child Complete\n");
	return 0;
}
