#include <stdio.h>
int main(void)
{
	FILE *fpRead;
	char ch;

	fpRead= fopen("file1.txt", "r");
	if(fpRead==NULL)
		printf("\n unable to open file for reading");
	else
	{
		// go to last char in file
		fseek(fpRead, -1L, SEEK_END);

		do
		{
			ch=fgetc(fpRead);
			//if(ch=='\n')  // add for windows os
				//fseek(fpRead, -1L, SEEK_CUR);
			printf("%c", ch);
			//getchar();

		}while(!fseek(fpRead,-2L, SEEK_CUR ));
	}


	return 0;
}
