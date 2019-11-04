#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int no, unit, tenth;

	printf("\n Enter No :: ");
	scanf("%d", &no);

	if(no==0)
	{
		printf("\n zero");
	}
	else
	{
		tenth=no/10;
		unit=no%10;

		switch(tenth)
		{
			case 1:
					switch(unit)
					{
						case 0: printf(" ten "); break;
						case 1: printf(" eleven "); break;
						case 1+1: printf(" twelve "); break;
						case 1*2+1: printf(" thirteen "); break;
					}
					break;
			case 1+1: printf("\n twenty "); break;
			case 1*2+1: printf("\n thirty "); break;
		}
		if(tenth!=1)
		{
			switch(unit)
			{
				//case 0: printf(" zero "); break;
				case 1: printf(" one "); break;
				case 1+1: printf(" two "); break;
				case 1*2+1: printf(" three "); break;
			}
		}
	}

	return 0;
}
