#include "shell.h"

/**
 * myGetLine - reads a line of text from STDIN
 * @buffer: buffer
 * @size: size
 * Return: string
 */

ssize_t myGetline(char **linePtr, size_t *n, FILE *stream)
{
	if (!linePtr || !n || !stream)
	{
		return -1;
	}

	int c;
	size_t i = 0;

	// Allocate initial memory for line
	if (*linePtr == NULL)
	{
		*n = 128;
		*linePtr = (char *)malloc(*n * sizeof(char));
		if (*linePtr == NULL)
		{
			free(*linePtr), *linePtr = NULL;
			return -1;
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		// Resize line if necessary
		if (i >= *n - 1)
		{
			*n *= 2;
			char *temp = (char *)realloc(*linePtr, *n * sizeof(char));
			if (temp == NULL)
			{
				return -1;
			}
			*linePtr = temp;
		}

		(*linePtr)[i++] = (char)c;

		if (c == '\n')
		{
			break;
		}
	}

	// Null-terminate the line
	if (i >= *n - 1 || c != '\n')
	{
		*n += 1;
		char *temp = (char *)realloc(*linePtr, *n * sizeof(char));
		if (temp == NULL)
		{
			return -1;
		}
		*linePtr = temp;
	}
	(*linePtr)[i] = '\0';

	if (i == 0 && c == EOF)
	{
		return -1;
	}

	return i;
}
