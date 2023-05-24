#include "shell.h"
/**
 * exit_b - Exit Statue Shell
 * @cd:Command
 * @in: input that user put
 * @argv:Program Name
 * @c: count
 * Return: exit
 */
void  exit_bul(char **cd, char *in)
{
	int st;
	int i = 0;

	if (cd[1] == NULL)
	{
		free(in);
		free(cd);
		exit(EXIT_SUCCESS);
	}
	while (cd[1][i])
	{
		if (_alphabet(cd[1][i++]) != 0)
		{
			break;
		}
		else
		{
			st = _atoin(cd[1]);
			free(in);
			free(cd);
			exit(st);
		}
	}
}

