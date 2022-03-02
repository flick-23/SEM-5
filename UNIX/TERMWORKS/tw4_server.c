// make use of mkfifo, read, write
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666
char fname[256];
int main()
{
	int readfd, writefd, fd;
	ssize_t n;
	char buf[512];
	if (mkfifo(FIFO1, PERMS) < 0)
		printf("\nCant read FIFO files");
	if (mkfifo(FIFO2, PERMS) < 0)
		printf("\nCan't read FIFO files");

	printf("\nWaiting for connection from the client");
	readfd = open(FIFO1, O_RDONLY, 0);
	writefd = open(FIFO2, O_WRONLY, 0);
	printf("\nConnection established!");

	read(readfd, fname, 256);
	printf("\nClient has requested file %s ", fname);

	if ((fd = open(fname, O_RDWR)) < 0)
	{
		strcpy(buf, "File does not exist!");
		write(writefd, buf, strlen(buf));
	}
	else
	{
		while ((n = read(fd, buf, 512)) > 0)
		{
			write(writefd, buf, n);
		}
	}
	close(readfd);
	unlink(FIFO1);
	close(writefd);
	unlink(FIFO2);
}