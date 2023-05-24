i#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
/**
 *find_command: function that get a command
 *@cd:the command to find
 *
 *@Return:full path of cd or NULL
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
  *splt: split a string
  *
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
/*execute_cd:a funcion executing a command*/

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
/*main:the main to use func*/
int main(void)
{
	char *in = NULL;
	size_t in_size = 0;
	char *args[];
	int nb;
	int i;

	while (1)
	{
		write(1, "$", 2);
		nb = getline(&in, &in_size, stdin);
		if (nb == -1)
		{
			perror("ERROR");
			break;
		}
		in[strlen(in) - 1] = '\0';
		splt(in, "\t\n");
		if(args[0] != NULL)
			execute_cd(args);
		else
		exit(0);
	}
	return (0);
}
