#include "shell.h"

char *_strdup(const char *str)
{
    char *ptr;
    int i, len = 0;

    if (str == NULL)
        return (NULL);
    while (*str != '\0')
    {
        len++;
        str++;
    }
    str = str - len;
    ptr = malloc(sizeof(char) * (len + 1));
    if(ptr == NULL)
        return (NULL);
        for( i = 0; i <= len; i++)
            ptr[i] = str[i];
            return (ptr);
}

int _strcmp(char *s1, char *s2)
{
    int cmp;

    cmp = (int)*s1 - (int)*s2;
    while(*s2)
    {
        if (*s1 != *s2)
            break;
            s1++;
            cmp = (int)*s1 - (int)*s2;
    }
    return (cmp);
}