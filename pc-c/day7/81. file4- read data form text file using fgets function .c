#include <stdio.h>
#define SIZE 10
int main(void)
{
	char arr[SIZE];

	FILE *fpRead=NULL;

	fpRead= fopen("/home/sunbeam/Desd_Aug19/file1/file1.txt", "r"); // in linux
	if(fpRead==NULL)
		printf("\n Unable to open file for reading");
	else
	{
		 while( fgets(arr, SIZE, fpRead)!=NULL)
		 {
			 fputs(arr, stdout); // print on console
//			 getchar();
		 }
		 printf("\n Data is read from file");
		 fclose(fpRead);
	}
	return 0;
}
