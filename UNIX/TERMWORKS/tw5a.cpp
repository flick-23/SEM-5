#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[], char *envp[])
{
	extern char **environ;
	int choice, i;
	char *env;
	cout << "\nChoose the damn method - \n1.Envp\n2.Environ\n3.Getenv\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		for (i = 0; envp[i] != (char *)0; i++)
		{
			cout << "\n"
				 << envp[i];
		}
		break;
	case 2:
		for (i = 0; environ[i] != (char *)0; i++)
		{
			cout << "\n"
				 << environ[i];
		}
		break;
	case 3:
		env = getenv("HOME");
		cout << "\nHOME:" << env;
		env = getenv("SHELL");
		cout << "\nSHELL:" << env;
		env = getenv("TERM");
		cout << "\nTERM:" << env;
		env = getenv("USER");
		cout << "\nUSER:" << env;
		env = getenv("PATH");
		cout << "\nPATH:" << env;
		break;
	default:
		printf("\nInvalid input dumbass!");
		break;
	}
}