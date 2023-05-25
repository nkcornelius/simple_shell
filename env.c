#include "shell.h"

/**
  *get_env - get the enviroment
  *@cmd: command to get
  *Return: enviromant or null
  **/
char *get_env(const char *cmd)
{
	int a;
	char *m;

	while (environ[a])
	{
		m = strtok(environ[a], "=");
		if (strcmp(m, cmd) == 0)
			return (strtok(NULL, "="));
		a++;
		}
	return (NULL);
}
/**main - the main to the function**/
int main(void)
{
	printf("%s/n", get_env("pwd"));
	return (0);
}
