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
