#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void system(const char *cmdstr)
{
	pid_t pid;
	if ((pid = fork()) == 0)
		execl("bin/sh", "sh", "-c", cmdstr, (char *)0);
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
return (status);
}

int main()
{
	int status;
	if ((status = system("date")) < 0)
		printf("system() error");
	if ((status = system("who")) < 0)
		printf("system() error");
	exit(0);
}
