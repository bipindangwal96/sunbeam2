#include<stdio.h>
void SumProd(int n1, int n2, int *ps, int *pp);
int main(void)
{
	int no1=10, no2=20 , sum=0, prod=0;
	SumProd(no1,no2,&sum, &prod);
	printf("\n %d + %d = %d ", no1, no2, sum);
	printf("\n %d * %d = %d ", no1, no2, prod);
	return 0;
}
void SumProd(int n1, int n2, int *ps, int *pp)
{
	*ps= n1+n2; // *(112) = 10+20 ==30
	*pp= n1*n2; // *(116) = 10*20 ==200;
 	return;
}


