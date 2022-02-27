#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
using namespace std;
#include<unistd.h>
int main()
{

	#ifdef _POSIX_JOB_CONTROL
		cout<<"system supports job control\n";
	#else
		cout<<"system does not suppor\n";
	#endif

	#ifdef _POSIX_SAVED_IDS
		cout<<"system supports saved set_UID and saved set-GID\n";
	#else
		cout<<"system does not support set_UID and saved set-GID\n";
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED
		cout<<"chown restricted option is:"<<_POSIX_CHOWN_RESTRICTED<<endl;
	#else
		cout<<"system does not support system-wide chown_restricted option\n";
	#endif

	#ifdef _POSIX_NO_TRUNC
		cout<<"Pathname truncnation option is:"<<_POSIX_NO_TRUNC<<endl;
	#else
		cout<<"system does not support system-wide Pathname truncnation option\n";
	#endif

	#ifdef _POSIX_VDISABLE
		cout<<"Diable character for terminal files  is:"<<_POSIX_VDISABLE<<endl;
	#else
		cout<<"system does not support _POSIX_VDISABLE\n";
	#endif
return 0;
}
