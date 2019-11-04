#include <stdio.h>
#define LEN 40
int main(void)
{
	FILE *fpReadWords=NULL;
	char word[LEN];
	int cnt;
	if((fpReadWords= fopen("file1.txt", "r"))==NULL)
		printf("\n unable to open file for reading");
	else
	{
		cnt=0;
		while(fscanf(fpReadWords,"%s", word)!=EOF)
		{
			printf("\n %d ] %s", ++cnt, word);
		}
		fclose(fpReadWords);
		printf("\n no of words =%d", cnt);
	}


	return 0;
}
