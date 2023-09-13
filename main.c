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
	(void) ac;

	while(1)
	{
		line = readline();
		if (line == NULL)
		{
			if(isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (0);
		}
		printf("%s", line);
		free(line);
		// add_history(line);
	}
}