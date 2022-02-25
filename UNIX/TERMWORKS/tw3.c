#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
	char temp[1000];
	setbuf(stdout,temp);
	struct flock fvar;
	int fdesc;
	char buf;
	int rc;
	off_t offset;
	pid_t pid=fork();
	fdesc=open(argv[1],O_RDWR);
	offset=lseek(fdesc,-100,SEEK_END);
	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_CUR;
	fvar.l_start=0;
	fvar.l_len=100;

	if(fcntl(fdesc,F_SETLK,&fvar)==-1)
	{
		printf("\n------------------------------------------\nFile has been locked by :\n");
		while(fcntl(fdesc,F_GETLK,&fvar)!=-1 && fvar.l_type!=F_UNLCK)
		{
			printf("\nFile: %s is locked by process with pid : %u",argv[1],fvar.l_pid);
			printf("from %ld th byte in file for %ld",fvar.l_start, fvar.l_len);
			printf("number of bytes , for %s\n",(fvar.l_type==F_WRLCK ? "write" : "read"));

			if(!fvar.l_len) break;

			fvar.l_start+=fvar.l_len;
			fvar.l_len=0;
		}
	}
	else {
	printf("\n----------------------\n");
	printf("\n\nFile %s was not locked and acquiring of Exclusive lock was ",argv[1]);
	printf("succesful by process Id %u \n",getpid());
		
	offset=lseek(fdesc,-50,SEEK_END);
	printf("\n\n Last 50 bytes of file %s = \n",argv[1]);
	while((rc=read(fdesc,&buf,1)>0))printf("%c",buf);
	offset-lseek(fdesc,-100,SEEK_END);
	fvar.l_type=F_UNLCK;
	fvar.l_whence=SEEK_CUR;
	fvar.l_start=0;
	fvar.l_len=100;

	fcntl(fdesc,F_SETLKW,&fvar);
	printf("\nFILE unlocked succesfully");
	}
return 0;
}
		
