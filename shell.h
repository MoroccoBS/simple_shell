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

#define WHITESPACE " \t\n="
// #define MAX_ALIASES 100
// #define MAX_ALIAS_LENGTH 50

// struct Alias
// {
// 	char name[MAX_ALIAS_LENGTH];
// 	char value[MAX_ALIAS_LENGTH];
// };

// extern struct Alias aliases[MAX_ALIASES];
// extern int numAliases;

/* =================== utils =========================*/
void freeArray(char **arr);									/*Function to free memory allocated for an array of strings */
void printError(char *name, char *cmd, int indexNum);		/*Function to print an error message */
void printErrorOfExit(char *name, char *cmd, int indexNum); /*Function to print an error message for exit */
char *_intToAscii();										/*Function to convert an integer to ASCII string*/
void reverseStr(char *string, int length);					/*Function to reverse a string*/
int isPositive(char *str);									/*Function to check if a string is positive*/
int _atoi(char *str);										/*Function to convert a string to an integer*/

/* ================== utils2 ==========================*/
int isPositive(char *str);								   /*Function to check if a string is positive*/
int _atoi(char *str);									   /*Function to convert a string to an integer*/
char *_getEnvironment(char *variable, char **environment); /*Function to get the value of an environment variable*/
char **tokenize(char *line);							   /*Function to tokenize a string into an array of strings*/
char *readline(void);									   /*Function to read a line of input from the user*/

/* ==================== strings =======================*/
int _strlen(char *string);			  /*Function to calculate the length of a string*/
char *_strcat(char *dest, char *src); /*Function to concatenate two strings*/
char *_strcpy(char *dest, char *src); /*Function to copy the contents of one string to another*/
char *_strdup(const char *str);		  /*Function to duplicate a string*/
int _strcmp(char *s1, char *s2);	  /*Function to compare two strings*/

/* ==================== execute ===================*/
int _execute(char **cmd, char **argv, char **environment, int indexNum); /*Function to execute a command*/
int _executeAlias(char **cmd, char **argv, char **environment, int indexNum);

/* ===================== handlers =================*/
char *handlePath(char *cmd, char **environment); /*Function to handle the PATH environment variable*/
void handleExit(char **command, char **argv, int *status, int index);
void handleBuiltIn(char **command, char **argv, int *status, int index, char **enviornment);
void handleEnv(char **command, int *status, char **enviornment);
void handleAlias(char **command);
char **getAliasValue(char *name);
/* ==================== myStrtok ===================*/
char *myStrtok(char *str, const char *delim); /*Function to split a string into tokens*/

/* ==================== myGetline ===================*/
ssize_t myGetline(char **linePtr, size_t *n, FILE *stream); /*Function to read a line of input from the user*/

/* ==================== isBuiltIn =================*/
int isBuiltIn(char *command);

// // Alias functions
// void printAlias(char *name);
// void printAliases();
// char *getAlias(char *name);
// void defineAlias(char *name, char *value);
// char *getAliasValue(char *name);

#endif
