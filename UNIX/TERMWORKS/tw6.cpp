// race condition
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
static void charatatime(char *);
int main()
{
	int pid, i;
	for (i = 0; i < 5; i++)
	{
		if (pid = fork() < 0)
		{ // error
			printf("\nFork error\n");
		}
		else if (pid == 0) // child
		{
			charatatime("I am a child\n");
		}
		else // parent
		{
			charatatime("I am parent\n");
		}
	}
	_exit(0);
}
void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for (ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}