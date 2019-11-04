
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int no1, no2, ans;
	char op;

	printf("\n Enter no1 :: ");
	scanf("%d", &no1);

	printf("\n Enter op :: ");
	scanf("%*c%c", &op);

	printf("\nop= %d", op);
	printf("\n Enter no2 :: ");
	scanf("%d", &no2);



	/*if(op=='+')
		ans=no1+no2;
	if (op=='-')
		 ans=no1-no2;
	if (op=='*')
		ans=no1*no2;
	if (op=='/')
		ans=no1/no2;
*/

	/*if(op=='+')
	{
			ans=no1+no2;
			//break; not allowed in if only
	}
	else if (op=='-')
	{
			 ans=no1-no2;
	}
	else if (op=='*')
			ans=no1*no2;
	else if (op=='/')
	{
		if(no2==0)
			{
				printf("\n divide by zero error");
				return 0;
			}
			else
				ans=no1/no2;
	}
	else
	{
		printf("\n invalid operator");
		exit(0);//return 0;
	}

	printf("\n %d %c %d=%d", no1, op, no2, ans);
	*/

	// switch
   switch(op)
   {
   	   //case 10.2: //error
   case "A":
   	   default : printf("\n invalid cases "); break;
   	 // case '+' : ans= no1+no2 ; break;
   	 //case 43 : ans= no1+no2 ; break;
   	//case 40+3 : ans= no1+no2 ; break;
 	case 8*5+3 : ans= no1+no2 ; break;
 	//case no1+no2 : ans= no1+no2 ; break; //not allowed
   	  case '-' : ans= no1-no2 ; break;
   	   case '*' : ans= no1*no2 ; break;
   	  case '/' :
   		  	  if(no2==0)
   		  	  {
   		  		  printf("\n can not divide by zero");
   		  		  return 0; // exit(0);
   		  	  }
   		  	  else
   		  		  ans= no1/no2 ; break;
   }
	printf("\n %d %c %d=%d", no1, op, no2, ans);
	return 0;
}
