#include "shell.h"

#define BUFFER_SIZE 1024
/**
  *main_b - the main function to buffer
  *Return: void
  **/

int main_b(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("$");
		read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (read_bytes == 0)
		{
			break;
		}
		buffer[read_bytes - 1] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			execlp(buffer, buffer, NULL);
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	return (EXIT_SUCCESS);
}
