#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
struct emp
{
	int empno;
	char name[10];
	float sal;
	signed comp:2;//int comp:2;
	unsigned laptop:1;
	unsigned mobile:1;
};

struct date1
{
	int dd;
	int mm;
	int yy;
};
struct date2
{
	short int dd;
	short int mm;
	short int yy;
};
struct date3
{
	unsigned  dd:5;
	unsigned  mm:4;
	unsigned  y:11;
};
struct date4
{
	signed  dd:6;
	signed  mm:5;
	signed  y:12;
};

struct demo
{
	signed var1:5;
	unsigned var2:5;
	//unsigned var3:7;
	signed var3:4;
};

int main(void)
{
	struct demo test;
	int i=0;
	for(i=0; i<100; i++)
	{
		test.var1=i;
		test.var2=i;
		printf("\n i=%d var1=%d var2=%d", i,test.var1, test.var2 );
	}
	{
	int no;
	printf("\n enter no :: ");
	scanf("%d", &no);
	test.var3=no;

	printf("\n test.var3=%d", test.var3);
	}
	return 0;
	struct emp e1={1, "ABC", 12000, 1,1,1};
	int no;
	printf("\n size of e1=%d",sizeof(e1));

	printf("\n %d %s %f %d %d %d ", e1.empno,e1.name, e1.sal, e1.comp, e1.laptop, e1.mobile);
	e1.comp==1 ? printf("\n have comp ") : printf("\n dont have comp ");

	printf("\n Enter 1 for having comp or 0 for not having comp \n");
	printf("\n enter your value :: ");
	//scanf("%d", &e1.comp); // error
	scanf("%d", &no);
	e1.comp=no;

	printf("\n %d %s %f %d %d %d ", e1.empno,e1.name, e1.sal, e1.comp, e1.laptop, e1.mobile);
	e1.comp==1 ? printf("\n have comp ") : printf("\n dont have comp ");
	return 0;
	printf("\n sizeof date1 =%d",sizeof(struct date1));
	printf("\n sizeof date2 =%d",sizeof(struct date2));
	printf("\n sizeof date2 =%d",sizeof(struct date3));


	return EXIT_SUCCESS;
}
