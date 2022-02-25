#include<stdio.h>
int main()
{
	#if __STDC__==0
	printf("cc is not ANSI C\n");
	#else
	printf("%s complied at %s:%s. This statement is at line %d\n",__FILE__,__DATE__,__TIME__,__LINE__);
	#endif
	return 0;
}z

