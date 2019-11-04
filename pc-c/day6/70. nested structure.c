#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
// way1
/*struct date
{
	int dd,mm, yy;
};
struct emp
{
	int empno;
	char name[10];
	float sal;
	struct date doj;
};*/
//way2
struct emp
{
	int empno;
	char name[10];
	float sal;

	struct date
	{
		int dd,mm, yy;
	}doj;
};

int main(void)
{
	struct emp e1;

	printf("\n Enter Emp no :: ");
	scanf("%d", &e1.empno);

	printf("\n Enter Name :: ");
	scanf("%s", e1.name);

	printf("\n Emp sal :: ");
	scanf("%f", &e1.sal);

	printf("\n Enter doj in DD-MM-YYYY format ::\n");
	scanf("%d%*c%d%*c%d", &e1.doj.dd, &e1.doj.mm, &e1.doj.yy);

	printf("\n=============================\n");
	printf("\n Emp No  name   Sal  \t doj \n");
	printf("%-5d %-10s %-4.2f %d-%d-%d", e1.empno, e1.name,e1.sal, e1.doj.dd, e1.doj.mm, e1.doj.yy );

	printf("\n\n\n");
	return EXIT_SUCCESS;
}
