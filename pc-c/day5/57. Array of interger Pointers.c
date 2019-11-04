#include<stdio.h>
int main(void)
{
	int *arr[5]; /*Array of integer pointer */
	int i=3, j=67,k=55,l=56,m=4,cnt;

	arr[0]=&i;
	arr[1]=&j;
	arr[2]=&k;
	arr[3]=&l;
	arr[4]=&m;
	for(cnt=0;cnt<5;cnt++)
	{
		printf("\n%u \t %u \t%d",&arr[cnt],arr[cnt],*(arr[cnt]));
	}
	return 0;
}
