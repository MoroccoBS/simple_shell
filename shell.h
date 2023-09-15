#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define WHITESPACE " \t\n"
/*extern char **enviornment;*/

char *readline(void);
int _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _execute(char **cmd, char **argv, char **enviornment);
char *_getenvironement(char *variable);
char *_handlepath(char *cmd);

void freeArray(char **arr);
char **tokenize(char *line);

#endif
