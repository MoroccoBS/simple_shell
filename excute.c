#include "shell.h"

/**
 * _execute - executes a command
 * @cmd: command
 * @argv: arguments
 * Return: statues
*/

int _execute(char **cmd, char **argv)
{
    pid_t children;
    int statues;

    children = fork();
    if (children == 0)
    {
        if (execve(cmd[0], cmd, envir) == -1)
        {
            perror(argv[0]);
            freearray2D(cmd);
            exit(0);
        }
    }
    else
    {
        waitpid(children, &statues, 0);
        freearray2D(cmd);
    }
    return (WEXITSTATUS(statues));
}
