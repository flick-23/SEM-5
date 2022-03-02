#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("\nUsage: ./a.out <destination file> <source_file>\n");
		return 0;
	}
	if (link(argv[1], argv[2]) == -1)
	{
		printf("\nLink Error!\n");
		return 1;
	}
	else
	{
		printf("\nHard link successfull!\n");
		return 0;
	}
}