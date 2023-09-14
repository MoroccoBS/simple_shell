#include "shell.h"

/**
 * readline - reads a line of text from STDIN
 * Return: string
 */

char *readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line), line = NULL;
	}

	return (line);
}
