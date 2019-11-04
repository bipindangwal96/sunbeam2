#include<stdio.h>
int flag;
void SumProdDiv(int n1, int n2, int *ps, int *pp, int *pd);
int main(void)
{
	int no1=20, no2=10 , sum=0, prod=0, div=0;
	SumProdDiv(no1,no2,&sum, &prod, &div);
	printf("\n %d + %d = %d ", no1, no2, sum);
	printf("\n %d * %d = %d ", no1, no2, prod);
	if(flag==1)
		printf("\n can not divide by zero");
	else
		printf("\n %d / %d = %d ", no1, no2, div);
	return 0;
}
void SumProdDiv(int n1, int n2, int *ps, int *pp, int *pd)
{
	*ps = n1+n2; // *(112) = 10+20 ==30
	*pp = n1*n2; // *(116) = 10*20 ==200;
	if(n2==0)
		flag=1;
	else
		*pd = n1/n2; // *(120)=  20/10 ==2
 	return;
}


