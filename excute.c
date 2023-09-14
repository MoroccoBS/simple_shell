#include "shell.h"

/**
 * _execute - executes a command
 * @cmd: command
 * @argv: arguments
 * @enviornment: environment
 * Return: status
 */

int _execute(char **cmd, char **argv, char **enviornment)
{
	pid_t childProcess;
	int status;

	childProcess = fork();
	if (childProcess == 0)
	{
		if (execve(cmd[0], cmd, enviornment) == -1)
		{
			perror(argv[0]);
			freeArray(cmd);
			exit(0);
		}
	}
	else
	{
		if (waitpid(childProcess, &status, 0) == -1)
		{
			perror("waitpid");
			freeArray(cmd);
			exit(1);
		}
		freeArray(cmd);
	}
	return (WEXITSTATUS(status));
}
