#include "shell.h"

/**
 * main - the shell
 * @argv: arguments
 * @ac: arguments
 * Return: 0
*/

int main(int ac, char **argv)
{
	char *line;
	char **tokens;
	int i;
	(void) ac;
	(void) argv;

	while (1)
	{
		line = readline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (0);
		}

		tokens = tokenize(line);
		if (!tokens)
		{
			continue;
		}
		for (i = 0; tokens[i]; i++)
		{
			printf("%s\n", tokens[i]);
			free(tokens[i]);
		}
		free(tokens), tokens = NULL;
	}
}
