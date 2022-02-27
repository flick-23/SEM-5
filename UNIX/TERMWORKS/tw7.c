#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t child_pid; /*create a child process*/
	child_pid = fork();

	if (child_pid == 0)
	{
		exit(0); /*this is the child process. exit immediately*/
	}
	else
	{
		sleep(3); /*this is the parent process.sleep for 3 units of time*/
		system("ps -e -o pid,ppid,stat,cmd");
	}
	return 0;
}
