#include "shell.h"

/**
 *find_command -  function that get a command
 *@cd:the command to find
 *
 *Return:full path of cd or NULL
 **/

char *find_command(char *cd)
{
	char *path = getenv("PATH");
	char *t;
	struct stat s;
	char *total_path;

	t = strtok(path, ":");

	while (t)
	{
		total_path = malloc(strlen(t) + strlen(cd) + 2);
		strcpy(total_path, t);
		strcpy(total_path, "/");
		strcpy(total_path, cd);
		if (stat(total_path, &s) == 0)
			return (total_path);
		free(total_path);
		t = strtok(NULL, ":");
	}
	return (NULL);
}
/**
  *splt -  split a string
  *@in: the input
  *@d: del
  *Return:tokens
  **/
char **splt(char *in, char *d)
{
	char **ts;
	char *t;
	int j = 0;

	ts = malloc(sizeof(char *) * 1024);
	t = strtok(in, d);
	while (t != NULL)
	{
		ts[j] = t;
		t = strtok(NULL, d);
		j++;
	}
	ts[j] = NULL;
	return (ts);
}
/**
  *execute_cd - a funcion executing a command
  *@args: charachters to ececute
 **/

void execute_cd(char *args[])
{
	pid_t child_pid;
	int status;
	char *path = NULL;

	child_pid = fork();
	path = find_command(args[0]);

	if (child_pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(path, args, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
