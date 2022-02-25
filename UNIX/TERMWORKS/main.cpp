#include <iostream>
#include<stdlib.h>
using namespace std;

extern char **environ;

int main(int argc,char *argv[],char *envp[])
{
    int choice=0;
    while(choice!=4)
    {cout<<"Press\n 1.to display environment list using command line arguments\n 2.to display environment using environ variable\n 3.to display values of environment variables using getenv function\n 4.to exit"<<endl;

    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"Printing environment list using command line arguments"<<endl;
    for(int i=0;envp[i]!=(char *)0;i++)
    {
        cout<<envp[i]<<endl;
    }
    break;

        case 2:cout<<"Printing environment list using environ variable"<<endl;
    for(int i=0;environ[i]!=(char *)0;i++)
    {
        cout<<environ[i]<<endl;
    }
    break;

        case 3:cout<<"Printing values of environment variables using getenv function"<<endl;
    char *env=getenv("HOME");
    cout<<"HOME : "<<env<<endl;
    env=getenv("SHELL");
    cout<<"SHELL : "<<env<<endl;
    env=getenv("TERM");
    cout<<"TERM : "<<env<<endl;
    env=getenv("USER");
    cout<<"USER : "<<env<<endl;
    env=getenv("PATH");
    cout<<"PATH : "<<env<<endl;
    break;

    }
    }
    return 0;
}
