#include "shell.h"
/**
 * _execute - executes a command
 * @cmd: command
 * @argv: arguments
 * @enviornment: environment
 * Return: status
 */
int _execute(char **cmd, char **argv, char **enviornment, int indexnum)
{
	char *fullcmd;
	pid_t childProcess;
	int status;

	fullcmd = handlepath(cmd[0]);
	if (!fullcmd)
	{
		error(argv[0], cmd[0], indexnum);
		freeArray(cmd);
		return (127);
	}
	childProcess = fork();
	if (childProcess == 0)
	{
		if (execve(fullcmd, cmd, enviornment) == -1)
		{
			free (fullcmd), fullcmd = NULL;
			freeArray(cmd);
		}
	}
	else
	{
		if (waitpid(childProcess, &status, 0) == -1)
		{
			perror("waitpid");
			freeArray(cmd);
			free (fullcmd), fullcmd = NULL;
		}
		freeArray(cmd);
	}
	return (WEXITSTATUS(status));
}
