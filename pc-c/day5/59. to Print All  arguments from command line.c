#include <stdio.h>
int main(int argc , char *argv[], char *envp[])
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("\n %d] %s", i, argv[i]);
	}
	printf("\n no of arguments =%d", argc);
	return 0;
}
// to compile ---> gcc CommandLine.c
// to run -----> ./a.out

// to give name for out file
// gcc -o CommandLine.out CommandLine.c
// ./CommandLine.out abcd hellow 123




