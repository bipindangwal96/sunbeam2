#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	{
		int no;
		printf("\n Enter No :: ");
		scanf("%d", &no);

		//condition? true part : condition ? true part : false part;
		no> 0 ? printf("\n %d is +ve", no) : no==0 ? printf("\n %d is zero ", no) : printf("\n %d is -ve", no);
	}
	{
		int no1, no2;
		printf("\n Enter No1 :: ");
		scanf("%d", &no1);
		printf("\n Enter No2 :: ");
		scanf("%d", &no2);

		no1>no2 ? printf("\n %d(no1) is max", no1): no1==no2 ? printf("%d(no1) equal to %d(no2)", no1, no2) : printf("\n %d (no2) is max ", no2);

	}

	return 0;
}
