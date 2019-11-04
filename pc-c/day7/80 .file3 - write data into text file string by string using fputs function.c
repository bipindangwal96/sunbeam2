#include <stdio.h>
#define SIZE 40
int main(void)
{
	char arr[SIZE];

	FILE *fpWrite=NULL;

	fpWrite= fopen("/home/sunbeam/Desd_Aug19/file1/file1.txt", "a"); // in linux
	if(fpWrite==NULL)
		printf("\n Unable to create file for writing");
	else
	{
		 while( fgets(arr, SIZE, stdin)!=NULL)
		 {
			 fputs(arr, fpWrite);
		 }
		 printf("\n Data is added to file");
		 fclose(fpWrite);
	}
	return 0;
}
