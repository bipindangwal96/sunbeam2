#include<stdio.h>
int main(void)
{
	int no;
	// print all 65 to 122
	/*for(no=65; no<=122; no++)
	{
		printf("\n %4d - %c ", no, no);
	}*/

	// pint 65 to 90
	/*for(no=65; no<=122; no++)
	{
		if(no>=91 && no<=96)
			break; // go out of loop
		printf("\n %4d - %c ", no, no);
	}*/
	// pint 65 to 90 and 97 to 122
	/*for(no=65; no<=122; no++)
	{
		if(no>=91 && no<=96)
			continue; // go next iteration
		printf("\n %4d - %c ", no, no);
	}*/

	// pint 65 to 90 and 97 to 122 using loops and logical not
	/*for(no=65; no<=122; no++)
	{
		if(!(no>=91 && no<=96))
			printf("\n %4d - %c ", no, no);
	}*/

	// pint 65 to 90 and 97 to 122 using loops with else
/*	for(no=65; no<=122; no++)
	{
		if(no>=91 && no<=96)
		{

		}
		else
			printf("\n %4d - %c ", no, no);
	}*/
	// pint 65 to 90 and 97 to 122 using loops with else
		for(no=65; no<=122; no++)
		{
			if(no>=91 && no<=96)
				;
			else
				printf("\n %4d - %c ", no, no);
		}

	return 0;
}

