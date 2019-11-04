#include<stdio.h>
//register int no2=10; //error
int no7; //0
int no8=100; // 100
//int no9=no1; //error
int main(void)
{
	register int no1=10;
	//printf("\n no1=%d %u", no1, &no1); //error
	printf("\n Enter No1 :: ");
	//scanf("%d", &no1); //error

	int no4=10;
	//static int no3=no4; error
	static int no5=10;
	static int no6;


	return 0;
}



