#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
	int res;

	cout << "Compile time values" << endl;
#ifdef _POSIX_CLK_TCK
	cout << "no of clock ticks per second:" << _POSIX_CLK_TCK << endl;
#else
	cout << "POSIX_CLK_TCK MACRO not defined" << endl;
#endif

#ifdef _POSIX_CHILD_MAX
	cout << "no of child processes created:" << _POSIX_CHILD_MAX << endl;
#else
	cout << "_POSIX_CHILD_MAX MACRO not defined" << endl;
#endif

#ifdef _POSIX_PATH_MAX
	cout << "no of maximum paths created:" << _POSIX_PATH_MAX << endl;
#else
	cout << "_POSIX_PATH_MAX MACRO not defined" << endl;
#endif

#ifdef _POSIX_NAME_MAX
	cout << "no of maximum characters in a file: " << _POSIX_NAME_MAX << endl;
#else
	cout << "_POSIX_NAME_MAX MACRO not defined" << endl;
#endif

#ifdef _POSIX_OPEN_MAX
	cout << "no of maximum opened files: " << _POSIX_OPEN_MAX << endl;
#else
	cout << "_POSIX_OPEN_MAX MACRO not defined" << endl;
#endif

	cout << endl
		 << "Run time values" << endl;
	if ((res = sysconf(_SC_CLK_TCK)) == -1)
		perror("sysconf");
	else
		cout << "no of clock ticks is:" << res << endl;

	if ((res = sysconf(_SC_CHILD_MAX)) == -1)
		perror("sysconf");
	else
		cout << "max no of child process is:" << res << endl;

	if ((res = pathconf("/", _PC_PATH_MAX)) == -1)
		perror("pathconf");
	else
		cout << "max length in bytes of a path is:" << res << endl;

	if ((res = pathconf("/", _PC_NAME_MAX)) == -1)
		perror("pathconf");
	else
		cout << "max length in bytes in a file name is:" << res << endl;

	if ((res = sysconf(_SC_OPEN_MAX)) == -1)
		perror("sysconf");
	else
		cout << "max no of opened files is:" << res << endl;
	return 0;
}
