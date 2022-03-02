// Create zombie process and then calls system to execute ps command, verify that the process is zombie
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		perror("\nFork error!");
	}
	else if (pid == 0) // child
	{
		_exit(0);
	}
	sleep(4); // parent
	system("ps -o pid,ppid,state,tty,command");
	_exit(0);
}