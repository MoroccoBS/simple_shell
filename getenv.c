#include "shell.h"

char *_getenv(char *variable)
{
    char *tmp, *key, *value, *env;
    int i;

    for (i = 0; enviornment[i]; i++)
    {
        tmp = _strdup(environment[i]);
        key = strtok(tmp, "=");
        if (strcmp(key, variable) == 0)
        {
            value = strtok(NULL, "\n")
            free(tmp);
            env = _strdup(value)
            return (value);
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
