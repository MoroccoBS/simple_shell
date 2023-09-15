#include "shell.h"
char *_handlepath(char *cmd)
{
    char *pathenv, *fullcmd, *directory;
    struct stat ad;
    for (i = 0; cmd[i], i++)
    {
        if (cmd[i] == "/")
        {
            if (stat(cmd, &ad) == 0)
                return (_strdup(cmd));

            return (NULL);   
        }
    }
    pathenv = _getenvironement("PATH");
    if (!pathenv)
        return (NULL);
    
     directory = strtok(pathenv, ":")
    while (directory)
    {
        fullcmd = malloc(_strlen(directory) + _strlen(cmd) + 2)
        if (fullcmd)
        {
            _strcpy(fullcmd, directory)
            _strcat(fullcmd, "./")
            _strcat(fullcmd, cmd)
            if (stat(fullcmd, &ad) == 0)
            {
                free (pathenv);
                return (fullcmd);
            }
            free (fullcmd), fullcmd = NULL;
            directory = strtok(NULL, ":")
        }
    }
    free (pathenv);
    return (NULL);
}