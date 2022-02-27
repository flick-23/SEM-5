#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Usage ./a.out sourcefile destination file\n";
		return 0;
	}
	if (link(argv[1], argv[2]) == -1)
	{
		cout << "Cant link\n";
		return 1;
	}
	else
	{
		cout << "Files have been linked\n";
		return 0;
	}
	return 0;
}
