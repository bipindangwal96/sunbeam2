#include <stdio.h>
int main(void)
{
	char ch;
	FILE *fpWrite=NULL;
	//fpWrite= fopen("file1.txt", "w");
	//fpWrite= fopen("file1.txt", "a");
	//fpWrite= fopen("d:\\sunbeam\\Desd_Aug19\\file1\\file1.txt", "a"); // in linux
	fpWrite= fopen("/home/sunbeam/Desd_Aug19/file1/file1.txt", "a"); // in linux
	if(fpWrite==NULL)
		printf("\n Unable to create file for writing");
	else
	{
		 while( (ch= fgetc(stdin))!=EOF)
		 {
			 fputc(ch, fpWrite);
		 }
		 printf("\n Data is added to file");
		 fclose(fpWrite);
	}
	return 0;
}
