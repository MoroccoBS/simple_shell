#include "shell.h"

// char **tokenize(char *line)
// {
//     char **tokens = NULL;
//     char *token = strtok((char *)line, WHITESPACE);
//     int count = 0;

//     while (token != NULL)
//     {
//         tokens = realloc(tokens, sizeof(char *) * (count + 2));
//         if (tokens == NULL)
//         {
//             // Memory allocation failed
//             return NULL;
//         }

//         tokens[count] = strdup(token);
//         if (tokens[count] == NULL)
//         {
//             // Memory allocation failed
//             return NULL;
//         }

//         count++;
//         token = strtok(NULL, WHITESPACE);
//     }

//     tokens[count] = NULL; // Set the last element to NULL

//     return tokens;
// }

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
	token = strtok(temp, " \t\n");
	if (!token)
	{
        free(token), token = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, " \t\n");
	}
	free(temp), temp = NULL;

	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[j] = token;
		token = strtok(NULL, " \t\n");
		j++;
	}
	// free(line), line = NULL;
	tokens[j] = NULL;
	return (tokens);
}
