#include "shell.h"

/**
 * _handlePath - handles the path
 * @cmd: command
 * @environment: environment
 * Return: path
 */
char *_handlePath(char *cmd, char **environment)
{
	char *pathEnv, *fullCmd, *directory;
	struct stat state;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &state) == 0)
				return (_strdup(cmd));

			return (NULL);
		}
	}

	pathEnv = _getEnvironment("PATH", environment);
	if (!pathEnv)
		return (NULL);

	directory = strtok(pathEnv, ":");
	while (directory)
	{
		fullCmd = malloc(_strlen(directory) + _strlen(cmd) + 2);
		if (fullCmd)
		{
			_strcpy(fullCmd, directory);
			_strcat(fullCmd, "./");
			_strcat(fullCmd, cmd);
			if (stat(fullCmd, &state) == 0)
			{
				free(pathEnv);
				return (fullCmd);
			}
			free(fullCmd), fullCmd = NULL;
			directory = strtok(NULL, ":");
		}
	}
	free(pathEnv);
	return (NULL);
}
