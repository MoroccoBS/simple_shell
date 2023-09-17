// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_ALIASES 10
// #define MAX_ALIAS_LENGTH 50

// typedef struct
// {
// 	char alias[MAX_ALIAS_LENGTH];
// 	char command[MAX_ALIAS_LENGTH];
// } Alias;

// Alias aliases[MAX_ALIASES];
// int numAliases = 0;

// void addAlias(char *alias, char *command)
// {
// 	if (numAliases >= MAX_ALIASES)
// 	{
// 		printf("Maximum number of aliases reached.\n");
// 		return;
// 	}

// 	strcpy(aliases[numAliases].alias, alias);
// 	strcpy(aliases[numAliases].command, command);
// 	numAliases++;

// 	printf("Alias '%s' added.\n", alias);
// }

// char *getAlias(char *alias)
// {
// 	int i;
// 	for (i = 0; i < numAliases; i++)
// 	{
// 		if (strcmp(aliases[i].alias, alias) == 0)
// 		{
// 			return aliases[i].command;
// 		}
// 	}

// 	return NULL;
// }

// int main()
// {
// 	// Example usage
// 	addAlias("ls", "ls -l");
// 	addAlias("ll", "ls -la");

// 	char *command = getAlias("ls");
// 	if (command != NULL)
// 	{
// 		printf("Alias found: %s", command);
// 	}
// 	else
// 	{
// 		printf("Alias not found.\n");
// 	}

// 	command = getAlias("ll");
// 	if (command != NULL)
// 	{
// 		printf("Alias found: %s", command);
// 	}
// 	else
// 	{
// 		printf("Alias not found.\n");
// 	}

// 	return 0;
// }
///////////////////////////////////////
// #include <stdio.h>
// #include <string.h>

// #define MAX_ALIASES 100

// typedef struct
// {
// 	char name[50];
// 	char value[50];
// } Alias;

// Alias aliases[MAX_ALIASES];
// int numAliases = 0;

// void addAlias(char *name, char *value)
// {
// 	if (numAliases < MAX_ALIASES)
// 	{
// 		strcpy(aliases[numAliases].name, name);
// 		strcpy(aliases[numAliases].value, value);
// 		numAliases++;
// 	}
// 	else
// 	{
// 		printf("Maximum number of aliases reached.\n");
// 	}
// }

// void printAliases()
// {
// 	for (int i = 0; i < numAliases; i++)
// 	{
// 		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
// 	}
// }

// int main()
// {
// 	// Example usage
// 	addAlias("ls", "ls --color=auto");
// 	addAlias("ll", "ls -l");

// 	printAliases();

// 	return 0;
// }

#include <stdio.h>
#include <string.h>

#define MAX_ALIASES 100
#define MAX_ALIAS_LENGTH 50

struct Alias
{
	char name[MAX_ALIAS_LENGTH];
	char value[MAX_ALIAS_LENGTH];
};

struct Alias aliases[MAX_ALIASES];
int numAliases = 0;

void printAliases()
{
	for (int i = 0; i < numAliases; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

void printAlias(char *name)
{
	for (int i = 0; i < numAliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
			return;
		}
	}
}

void defineAlias(char *name, char *value)
{
	for (int i = 0; i < numAliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			strcpy(aliases[i].value, value);
			return;
		}
	}

	if (numAliases < MAX_ALIASES)
	{
		strcpy(aliases[numAliases].name, name);
		strcpy(aliases[numAliases].value, value);
		numAliases++;
	}
}

int main()
{
	// Example usage
	defineAlias("ls", "ls --color=auto");
	defineAlias("gcc", "gcc -Wall");

	printAliases();

	printf("\n");

	printAlias("ls");
	printAlias("gcc");

	return 0;
}