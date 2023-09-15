#include "shell.h"

/**
 * freeArray - free an array of tokens
 * @arr: array to get freedom
 * Return: void
 */

void freeArray(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	};
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]), arr[i] = NULL;
	};
	free(arr), arr = NULL;
}

void error(char *name, char *cmd, int indexnum)
{
	char *index, message[] = ": not found\n";
	index = _inttoascii();
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, message, _strlen(message));

	free (index);
}
char *_inttoascii()
{
    char buffer[25];
    int i = 0;

    if (n == 0)
        buffer[i++] = '0';
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 0;
        }
    }
    buffer[i] = '0';
    reversestr(buffer, i);

    return (strdup(buffer));
}
void reversestr(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}
