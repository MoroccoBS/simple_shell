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

/* =================== utils =========================*/
void freeArray(char **arr);
void printError(char *name, char *cmd, int indexNum);
void printErrorOfExit(char *name, char *cmd, int indexNum);
char *_intToAscii();
void reverseStr(char *string, int length);
int isPositive(char *str);
int _atoi(char *str);

/* ================== utils2 ==========================*/
int isPositive(char *str);
int _atoi(char *str);
char *_getEnvironment(char *variable, char **environment);
char **tokenize(char *line);
char *readline(void);

/* ==================== strings =======================*/
int _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);

/* ==================== execute ===================*/
int _execute(char **cmd, char **argv, char **environment, int indexNum);

/* ===================== handlers =================*/
char *_handlePath(char *cmd, char **environment);
void handleExit(char **command, char **argv, int *status, int index);
void handleBuiltIn(
	char **command, char **argv, int *status, int index, char **enviornment);
void handleEnv(char **command, int *status, char **enviornment);

/* ==================== myStrtok ===================*/
char *myStrtok(char *str, const char *delim);

/* ==================== myGetline ===================*/
ssize_t myGetline(char **linePtr, size_t *n, FILE *stream);

/* ==================== isBuiltIn =================*/
int isBuiltIn(char *command);

#endif
