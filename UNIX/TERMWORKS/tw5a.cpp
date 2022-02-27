#include <iostream>
#include <stdlib.h>

using namespace std;
// extern char **environ
int main()
{

	/*for(int i=0;environ[i]!=(char*)0;i++)
	{
		cout<<environ[i]<<"\n";
	}
	return 0;

	/*for(int i=0;envp[i]!=(char*)0;i++) include command line arguments
	{
		cout<<envp[i]<<"\n";
	}
	return 0;*/

	char *env = getenv("HOME");
	cout << "HOME " << env << "\n";

	env = getenv("SHELL");
	cout << "SHELL " << env << "\n";

	env = getenv("TERM");
	cout << "TERM " << env << "\n";

	env = getenv("USER");
	cout << "USER " << env << "\n";

	env = getenv("PATH");
	cout << "PATH " << env << "\n";
	return 0;
}
