#ifndef _SHELL_H_
#define _SHELL_Hi

extern char **environ;

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/*functions*/
char *get_env(const char *cmd);
void exit_bul(char **cd, char *in);
void execute_cd(char *args[]);
char **splt(char *in, char *d);
char *find_command(char *cd);
int _alphabet(int c);
int _atoin(char *s);

#endif
