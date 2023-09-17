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
/*extern char **environment;*/

// Function to read a line of input from the user
char *readline(void);

// Function to calculate the length of a string
int _strlen(char *string);

// Function to concatenate two strings
char *_strcat(char *dest, char *src);

// Function to copy the contents of one string to another
char *_strcpy(char *dest, char *src);

// Function to duplicate a string
char *_strdup(const char *str);

// Function to compare two strings
int _strcmp(char *s1, char *s2);

// Function to execute a command
int _execute(char **cmd, char **argv, char **environment, int indexNum);

// Function to get the value of an environment variable
char *_getEnvironment(char *variable, char **environment);

// Function to handle the PATH environment variable
char *_handlePath(char *cmd, char **environment);

// Function to print an error message
void printError(char *name, char *cmd, int indexNum);

// Function to convert an integer to ASCII string
char *_intToAscii();

// Function to reverse a string
void reverseStr(char *string, int length);

// Function to free memory allocated for an array of strings
void freeArray(char **arr);

// Function to tokenize a string into an array of strings
char **tokenize(char *line);

// Function to split a string into tokens
char *myStrtok(char *str, const char *delim);

// Function to read a line of input from the user
ssize_t myGetline(char **linePtr, size_t *n, FILE *stream);

#endif
