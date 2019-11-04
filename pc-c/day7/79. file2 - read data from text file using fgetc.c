#include <stdio.h>

int main(void)
{
	char ch;
	FILE *fpRead=NULL;
	int cnt, alphabets, digits, spaces, lines,tabs;
                                                                   // a or a+ 
	fpRead= fopen("/home/sunbeam/Desd_Aug19/file1/file1.txt", "r"); // in linux
	if(fpRead==NULL)
		printf("\n Unable to read file for writing");
	else
	{
		cnt= alphabets= digits= spaces= lines=tabs=0;
		 while( (ch= fgetc(fpRead))!=EOF)
		 {
			 fputc(ch, stdout); // to print on console
			// getchar(); //prees key from keyboard
			 cnt++;
			 if( (ch>=65 && ch<=90) || (ch>=97 && ch<=122))
			     alphabets++;
			 else if( ch>=48 && ch<=57)
				  digits++;
			 else if( ch== ' ' || ch==32)
				 spaces++;
			 else if( ch== '\t')
			 	 tabs++;
			 else if( ch== '\n')
			 	  lines++;


		 }
		 printf("\n Data read from  file");
		 printf("\n no of char =%d", cnt);
		 printf("\n no of alphabets =%d", alphabets);
		 printf("\n no of digits =%d", digits);
		 printf("\n no of lines =%d",lines);
		 printf("\n no of tabs =%d", tabs);
		 printf("\n no of spaces  =%d", spaces);
		 fclose(fpRead);
	}
	return 0;
}
