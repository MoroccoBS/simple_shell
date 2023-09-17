#include "shell.h"

/**
 * tokenize - splits a string into words
 * @line str: the input string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **tokenize(char *line)
{
	char *token = NULL, *temp = NULL;
	char **tokens = NULL;
	int i = 0, j = 0;

	if (!line)
	{
		return (NULL);
	};
	temp = _strdup(line);
	token = myStrtok(temp, WHITESPACE);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = myStrtok(NULL, WHITESPACE);
	}
	free(temp), temp = NULL;

	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = myStrtok(line, WHITESPACE);
	while (token)
	{
		tokens[j] = _strdup(token);
		token = myStrtok(NULL, WHITESPACE);
		j++;
	}
	free(line), line = NULL;
	tokens[j] = NULL;
	return (tokens);
}
