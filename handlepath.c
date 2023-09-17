#include "shell.h"

/**
 * _handlePath - handles the path
 * @cmd: command
 * @environment: environment
 * Return: path
 */

char *_handlePath(char *cmd, char **environment)
{
	char *pathEnv, *pathEnvCopy, *fullCmd, *directory;
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

	pathEnvCopy = _strdup(pathEnv);
	directory = myStrtok(pathEnvCopy, ":");
	while (directory)
	{
		fullCmd = malloc(_strlen(directory) + _strlen(cmd) + 2);
		if (fullCmd)
		{
			_strcpy(fullCmd, directory);
			_strcat(fullCmd, "/");
			_strcat(fullCmd, cmd);
			if (stat(fullCmd, &state) == 0)
			{
				free(pathEnvCopy);
				free(pathEnv);
				return (fullCmd);
			}
			free(fullCmd);
		}
		directory = myStrtok(NULL, ":");
	}
	free(pathEnvCopy);
	free(pathEnv);
	return (NULL);
}
