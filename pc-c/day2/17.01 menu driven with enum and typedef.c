#include<stdio.h>
/*typedef enum menuchoice
{
	EXIT=0,ADDITION, MINUS,MULTIPLY, DIVISION
}MENUCHOICE;*/

enum menuchoice
{
	EXIT=0,ADDITION, MINUS,MULTIPLY, DIVISION
};
typedef enum menuchoice MENUCHOICE;
int main(void)
{
	int no1, no2, ans;
	MENUCHOICE choice;//enum menuchoice choice;
	do
	{
		printf("\n 1. Addition \n 2. Minus \n 3. Multiply \n 4. Division \n 0. Exit ");
		printf("\n Enter Your choice ::  ");
		scanf("%d", &choice);

		if(choice==0)
			return 0;
		printf("\n Enter no1 :: ");
		scanf("%d", &no1);

		printf("\n Enter no2 :: ");
		scanf("%d", &no2);





		switch(choice)
		{
			default: printf("\n invalid choice");
					continue;
			case EXIT: // EXIt
					return 0; // exit(0);
			case ADDITION:// addition
				  ans= no1+no2; break;
			case MINUS:// minus
				  ans= no1-no2; break;
			case MULTIPLY:// multiply
				ans= no1*no2; break;
			case DIVISION:// division
				 ans= no1/no2; break;
		}
		printf("\n ans=%d", ans);
		printf("\n Enter 1 to continue or 0 to exit :: ");
		scanf("%d", &choice);


	} while(choice!=0);
	return 0;
}

