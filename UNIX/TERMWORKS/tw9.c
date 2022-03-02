// implement system fucntion
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int system(const char *str)
{
	pid_t pid;
	int status;
	if (str == NULL)
	{
		return (1);
	}
	if (pid = fork() < 0)
	{
		status = -1;
	}
	else if (pid == 0)
	{
		execl("/bin/sh", "sh", "-c", str, (char *)0);
		_exit(127);
	}
	else
	{
		while (waitpid(pid, &status, 0) < 0)
		{
			if (errno != EINTR)
				status = -1;
			break;
		}
	}
	return status;
}
int main()
{
	int status;
	if (status = system("date") < 0)
		printf("system() error");
	if (status = system("who") < 0)
		printf("system() error");
	exit(0);
}