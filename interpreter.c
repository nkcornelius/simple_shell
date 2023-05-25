#include "shell.h"


#define BUFFER_SIZE 1024

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;
	pid_t child_pid;
	int status;

	while (1)
	{
		/**Display the prompt**/
		printf("$ ");
		read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		if (read_bytes == 0)
		{
			printf("\n");
			break;
		}
		/** Remove the newline character**/
		buffer[read_bytes - 1] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			/** Child process**/
			execlp(buffer, buffer, NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			/**Parent process**/
			waitpid(child_pid, &status, 0);
		}
	}
	return (EXIT_SUCCESS);
}
