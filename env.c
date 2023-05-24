#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *get_env(const char *cmd)
{
	extern char **environ;
	int a;
	char *m;

	while (environ[a])
	{
		m = strtok(environ[a], "=");
		if (strcmp(m, cmd) ==0)
			return (strtok(NULL, "="));
		a++;
		}
	return (NULL);
}

int main(void)
{
	printf("%s/n", get_env("pwd"));
	return (0);
}
