
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	// condition ? true part : false part ;
	int no;
	printf("\n enter No :: ");
	scanf("%d", &no);

	no%2==0 ?  printf("\n %d is even ", no): printf("\n %d is odd ", no);
	no%2 ?  printf("\n %d is odd ", no): printf("\n %d is even ", no);
	return 0;
}
