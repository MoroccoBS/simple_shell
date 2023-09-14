#include "shell.h"

/**
 * main - the shell
 * @argv: arguments
 * @ac: arguments
 * @enviornment: environment
 * Return: 0
 */

int main(int ac, char **argv, char **enviornment)
{
	char *line, **tokens;
	int status = 0;
	(void)ac;

	while (1)
	{
		line = readline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (status);
		}

		tokens = tokenize(line);
		if (!tokens)
		{
			continue;
		}

		status = _execute(tokens, argv, enviornment);
	}
}
