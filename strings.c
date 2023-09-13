#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @string: string
 * Return: length
*/


int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		;
	}
	return (i);
}

/**
 * _strcat - concatenate two strings
 * @dest: first string
 * @src: second string
 * Return: concatenated string
*/

char *_strcat(char *dest, char *src)
{
	int len = 0;
	int j = 0;

	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[j] != '\0')
	{
		dest[len + j] = src[j];
		j++;
	}
	dest[len + j] = '\0';
	return (dest);
}

/**
 * *_strcpy - copies the string pointed
 * @dest: buffer
 * @src: string to be pointed by src
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_start);
}
