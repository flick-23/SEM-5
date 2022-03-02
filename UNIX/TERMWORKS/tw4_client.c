// make use of mkfifo, open,read,write function
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
    char buf[512];
    int readfd, writefd, fd;
    ssize_t n;
    printf("Trying to connec to the server ... ");
    writefd = open(FIFO1, O_WRONLY, 0);
    readfd = open(FIFO2, O_RDONLY, 0);
    printf("\nConnected ...");

    scanf("%s", fname);
    write(writefd, fname, strlen(fname));
    printf("\nWaiting for server to reply\n");
    while ((n = read(readfd, buf, 512)) > 0)
        write(1, buf, n);
    close(readfd);
    close(writefd);
    return 0;
}