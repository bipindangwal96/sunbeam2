

#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
int main(void)
{
	{
		int no1, no2;
		float no3;
		printf("\n Enter No1 :: ");
		scanf("%d", &no1);
		printf("\n Enter No2 :: ");
		scanf("%d", &no2);
		printf("\n Enter no3 ::");
		scanf("%f", &no3);
		printf("\nno1=%10d no2=%10d", no1, no2);
		printf("\nno1=%-10d no2=%-10d", no1, no2);
		printf("\n no3=%f", no3);
		printf("\n no3=%.2f", no3);
		printf("\n no3=%.0f", no3);

	}
	return 0;
	{
	
	printf("\n int\t\t %%d %d   %d to %d", sizeof(int), INT_MIN, INT_MAX);
	printf("\n unsigned int   %%u %d 0 to %u", sizeof(unsigned int),UINT_MAX);

	}
	return 0;

	{
		char ch;
		int no=100;
		printf("\n sizeof(10)=%d", sizeof(10));
		printf("\n sizeof(10.2)=%d", sizeof(10.2));
		printf("\n sizeof(10.2f)=%d", sizeof(10.2f));
		printf("\n sizeof(10.2F)=%d", sizeof(10.2F));
		printf("\n sizeof(ch)=%d", sizeof(ch));
		printf("\n sizeof('A')=%d", sizeof('A'));
		printf("\n sizeof(++no)=%d", sizeof(++no));
		printf("\n no=%d", no);
	}
	return 0;
	{
		int no1;
		char ch;
		/*printf("\n enter ch:: ");
		//scanf("%*c%c", &ch); // %*c ingone char
		//getchar();
		scanf("%c", &ch);*/


		printf("\n enter no1 ::");
		scanf("%d", &no1);
		printf("\n no1=%d", no1);

		printf("\n enter ch:: ");
		//scanf("%*c%c", &ch); // %*c ingone char
		getchar();
		scanf("%c", &ch);

		printf("\n ch=%c ch=%d",ch, ch);

	}
	return 0;
	{
		int no1, no2;
		printf("\n enter no1 & no2 ::");
		printf("%d", scanf("%d%d", &no1, &no2));
		printf("\n no1=%d no2=%d", no1, no2);

	}
	return 0;
	{
		int no1;
		printf("\n Enter No1 :: ");
		//scanf("enter no1%d", &no1); //wrong output
		//scanf("%d", &no1);
		//scanf("\n %d", &no1); // extra input req

		printf("\n no1=%d [%u]", no1, &no1);
		printf("\n no1=%d [%p]", no1, &no1);
	}
	return 0;
	{
		printf("\n %d", 10/3);
	}
	//exit(0); //function
	//return 0; // jump statements

	printf ("no of char =%d",printf("\n welcome \tto sunbeam\n")); /* prints welcome to sunbeam */
	printf("\n \\n = %d", '\n');
	printf("\n \\t = %d", '\t');
	printf("\n \\r = %d", '\r');
	printf("\n \\b = %d", '\b');
	printf("\n \\a = %d", '\a');


	//printf(" " sunbeam " ");
	printf(" \" sunbeam \" ");
	printf(" \n ' sunbeam' \n");
	printf(" \n \' sunbeam \' \n");

	/// \b  \r \a \

	return EXIT_SUCCESS;
}
