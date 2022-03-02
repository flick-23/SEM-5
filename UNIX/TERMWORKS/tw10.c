// setup a real time clock interval using alarm API
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void call(int sig_no)
{
	alarm(5);
	printf("\nAYo Mothafakaaasss!\n");
}
int main()
{
	struct sigaction action;
	action.sa_handler = (void (*)(int))call;
	sigaction(SIGALRM, &action, 0);
	alarm(2);
	sleep(5);
	return 0;
}