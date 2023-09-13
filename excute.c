#include "shell.h"
int _execute(char **cmd, char **argv)
{
    pid_t children;
    int statues

    children = fork();
    if (child == 0)
    {
        if (execve(cmd[0], cmd, envir) == -1)
        {
            prerror(argv[0]);
            freearry2D(cmd);
            exit(0);
        }
        //on shell.h => extern char **envir + function 
    }
    else
    {
        waitpid(children, &status, 0);
        freearray2D(cmd);
    }
    return (WEXITSATATUS(status));
}