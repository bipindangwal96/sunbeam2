#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char ch;

	printf("\n Enter char :: ");
	scanf("%c", &ch);

	printf("\n ch=%c ch=%d", ch, ch);
	// to convert to capital //A -65  Z=90   a=97 z=122

	if(ch>=97 && ch<=122)
	{
		ch-=32; // ch=ch-32;
	}
	printf("\n ch=%c ch=%d", ch, ch);
	//if(ch=='A' || 'E' || 'I' || 'O' || 'U') // wrong

	if(ch=='A' || ch=='E' || ch== 'I' || ch=='O' || ch=='U')
		printf("\n %c is vov", ch);
	else if(ch>=65 && ch<=90)
		printf("\n %c is con", ch);
	else if(ch>=48 && ch<=57)  //else if( ch>='0' && ch<='9')
		printf("\n %c is digit", ch);
	else
		printf("\n %c is other char", ch);
	return 0;
}
