#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *ptr=NULL;
	//ptr= (char*)malloc(sizeof(char)*-1); // fail
	ptr= (char*)malloc(sizeof(char)*1);
	if(ptr==NULL)
		printf("\n unable to allocate memory ");
	else
	{
		printf("\n ptr=%u &ptr=%u", ptr, &ptr);
		//*ptr=55;

		printf("\n Enter *ptr=");
		scanf("%c", ptr);
		printf("\n *ptr=%c", *ptr);
		free(ptr);
		ptr=NULL;
		printf("\n memory is freed");
		//printf("\n *ptr=%d", *ptr); //error
	}
	return 0;
}
// to compile prog --->> gcc demo4.c
// to run ---->>> ./a.out
// to check memory leakage -->> valgrind ./a.out



