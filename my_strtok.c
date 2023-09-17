#include "shell.h"

/**
 * _strtok - splits a string into tokens
 * @str: the input string
 * @delim: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */

char *myStrtok(char *str, const char *delim)
{
	static char *current = NULL;
	if (str != NULL)
	{
		current = str;
	}
	if (current == NULL || *current == '\0')
	{
		return NULL;
	}

	// Skip initial delimiters
	while (*current != '\0')
	{
		int isDelimiter = 0;
		for (int i = 0; delim[i] != '\0'; i++)
		{
			if (*current == delim[i])
			{
				current++;
				isDelimiter = 1;
				break;
			}
		}
		if (!isDelimiter)
		{
			break;
		}
	}

	char *token = current;
	while (*current != '\0')
	{
		for (int i = 0; delim[i] != '\0'; i++)
		{
			if (*current == delim[i])
			{
				*current = '\0';
				current++;
				while (*current != '\0')
				{
					int isDelimiter = 0;
					for (int j = 0; delim[j] != '\0'; j++)
					{
						if (*current == delim[j])
						{
							current++;
							isDelimiter = 1;
							break;
						}
					}
					if (!isDelimiter)
					{
						break;
					}
				}
				return (*token == '\0') ? NULL : token;
			}
		}
		current++;
	}
	return (*token == '\0') ? NULL : token;
}
