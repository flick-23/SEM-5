// Avoid zombie process
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid = fork();
	if (pid == 0)
	{
		// first child
		pid = fork();
		if (pid == 0)
		{ // second child
			sleep(1);
			printf("\nSecond child : My Parent PID is %d\n", getppid());
		}
	}
	else
	{ // parent process
		wait(NULL);
		sleep(2);
		system("ps -o pid,ppid,state,tty,command");
	}
	return 0;
}