#include<stdio.h>
int main(void)
{
	// 2. print sum of n numbers
	/*int no, counter, sum;

	printf("\n Enter No :: ");
	scanf("%d", &no);

	for(counter=sum=0;counter<=no; counter++)
	{
		printf("%5d  ", counter);
		if(counter<no)
			printf(" + ");
		sum+=counter; //sum= sum+counter;
	}
	printf(" =%d", sum);
	*/

	//3. factorial of no

	/*int no, counter, fact;

	/*printf("\n Enter No :: ");
	scanf("%d", &no);

	for(counter=fact=1; counter<=no; counter++)
	{
		printf("%5d*", counter);
		fact*=counter;
	}
	printf(" =%d", fact);
	*/

	// count no of digits
	/*int no, counter;

	printf("\n Enter No :: ");
	scanf("%d", &no);
	if(no==0)
		printf("\n no of digits  =1");
	else
	{
		while (no!=0)
		{
			no/=10; // no=no/10;
			counter++;
		}
		printf("\n no of digits=%d", counter);
	}*/


	/// sum of digits
	int no, rem , sum;

	printf("\n Enter No :: ");
	scanf("%d", &no);

	rem=sum=0;
	while(no!=0)
	{
		rem= no%10;
		no/=10; // no=no/10;
		sum+=rem;// sum=sum+rem;
	}
	printf("\n sum of digits=%d", sum);
	return 0;
}

