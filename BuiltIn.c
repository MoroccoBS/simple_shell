#include "shell.h"

/**
 * isBuiltIn - checks if the command is a built-in
 * @command: command
 * Return: 0 or 1
 */

int isBuiltIn(char *command)
{
	int i;

	char *builtIns[] = {
		"exit", "cd", "env", "setenv", "alias", NULL};

	for (i = 0; builtIns[i]; i++)
	{
		if (_strcmp(builtIns[i], command) == 0)
		{
			return (1);
		}
	}

	return (0);
}

/**
 * handleBuiltIn - handles built-in commands
 * @command: command
 * @argv: arguments
 * @status: status to exit with
 * @index: index
 * @enviornment: enviornment
 */
void handleBuiltIn(
	char **command, char **argv, int *status, int index, char **enviornment)
{
	(void)index;
	if (_strcmp(command[0], "exit") == 0)
	{
		handleExit(command, argv, status, index);
	}
	/*else if (_strcmp(command[0], "cd"))
	{
		handleCd();
	}*/
	else if (_strcmp(command[0], "env") == 0)
	{
		handleEnv(command, status, enviornment);
	}
	else if (_strcmp(command[0], "alias") == 0)
	{
		handleAlias(command);
	}
}

/*if (_strcmp(tokens[0], "alias") == 0)
{
	if (tokens[1] && tokens[2])
	{
		defineAlias(tokens[1], tokens[2]);
		freeArray(tokens);
	}
	else if (tokens[1])
	{
		printAlias(tokens[1]);
		freeArray(tokens);
	}
	else
	{
		printAliases();
		freeArray(tokens);
	}
	continue;
}*/
