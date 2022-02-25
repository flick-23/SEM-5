#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>

void wakeup()
{
	printf("Hello\\n");
	printf("-------------------\n");
}

int main()
{
	int i;
	struct sigaction action;
	action.sa_handler=wakeup;
	action.sa_flags=SA_RESTART;
	sigemptyset(&action.sa_mask);
	if(sigaction(SIGALRM,&action,0)==-1)
	{
		perror("sigaction");
	}
	while(1)
	{
		alarm(5);
		pause();
		printf("waiting for alarm\n");
	}
	return 0;
}

