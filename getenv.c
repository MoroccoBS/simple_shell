#include "shell.h"

/**
 * _getEnvironment - gets the value of an environment variable
 * @variable: the name of the environment variable
 * @environment: the environment
 * Return: the value of the environment variable
 */

char *_getEnvironment(char *variable, char **environment)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environment[i]; i++)
	{
		tmp = _strdup(environment[i]);
		key = myStrtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = myStrtok(NULL, "\n");
			env = _strdup(value);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
