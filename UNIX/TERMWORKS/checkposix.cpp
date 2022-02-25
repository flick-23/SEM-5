#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main()
{
	#ifdef _POSIX_VERSION
		cout<<"system confirms to POSIX:"<<_POSIX_VERSION<<endl;
	#else
		cout<<"_POSIX_VERSION is undefined\n";
	#endif
return 0;
}
