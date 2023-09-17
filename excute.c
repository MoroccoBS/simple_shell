#include "shell.h"
/**
 * _execute - executes a command
 * @cmd: command
 * @argv: arguments
 * @environment: environment
 * @indexNum: index
 * Return: status
 */
int _execute(char **cmd, char **argv, char **environment, int indexNum)
{
	char *fullCmd;
	pid_t childProcess;
	int status;
	// int i;

	// if (_strcmp(cmd[0], "exit") == 0) // Check if the command is 'exit'
	// {
	// 	if (cmd[1]) // If there is an argument after 'exit'
	// 	{
	// 		int exit_status = atoi(cmd[1]);
	// 		freeArray(cmd);	   // Convert the argument to an integer
	// 		exit(exit_status); // Exit with the specified status
	// 	}
	// 	else
	// 	{
	// 		freeArray(cmd);
	// 		exit(EXIT_SUCCESS); // If there is no argument, exit successfully
	// 	}
	// }

	// for (i = 0; cmd[i]; i++)
	// {
	// 	if (_strcmp(cmd[i], "exit") == 0) // exit
	// 	{
	// 		if (i < 1)
	// 		{
	// 			freeArray(cmd);
	// 			exit(EXIT_SUCCESS);
	// 		}
	// 		else
	// 		{
	// 			freeArray(cmd); // Convert the argument to an integer
	// 			exit(status);	// Exit with the specified status
	// 		}
	// 	}
	// }
	if (_strcmp(cmd[0], "exit") == 0)
	{
		freeArray(cmd);
		exit(EXIT_SUCCESS);
	}

	fullCmd = _handlePath(cmd[0], environment);
	if (!fullCmd)
	{
		printError(argv[0], cmd[0], indexNum);
		freeArray(cmd);
		return (127);
	}
	childProcess = fork();
	if (childProcess == 0)
	{
		if (execve(fullCmd, cmd, environment) == -1)
		{
			perror("execve");
		}
		free(fullCmd), fullCmd = NULL;
		freeArray(cmd);
		exit(EXIT_FAILURE); // Add this line to terminate the child process
	}
	else
	{
		if (waitpid(childProcess, &status, 0) == -1)
		{
			perror("waitpid");
		}
		free(fullCmd), fullCmd = NULL;
		freeArray(cmd);
	}
	return (WEXITSTATUS(status));
}
