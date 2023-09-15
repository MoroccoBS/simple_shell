#include "shell.h"

/**
 * _getEnvironment - gets the value of an environment variable
 * @variable: the name of the environment variable
 * @environment: the environment
 * Return: the value of the environment variable
 */

char *_getEnvironment(char *variable, char **environment)
{
	char *tmp, *key, *value;
	int i;

	for (i = 0; environment[i]; i++)
	{
		tmp = _strdup(environment[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			free(tmp);
			return (value);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
