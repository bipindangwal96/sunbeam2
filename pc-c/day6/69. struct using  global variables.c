#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct emp
{
	int empno;
	char name[10];
	float sal;
};
struct emp e1;
void AcceptEmpInfo();
void DisplayEmpInfo();
int main(void)
{
	printf("\n Enter info of employee :: ");
	AcceptEmpInfo();

	printf("\n Employee info ::  \n");
	DisplayEmpInfo();

	printf("\n\n\n");
	return EXIT_SUCCESS;
}
void AcceptEmpInfo()
{
	printf("\n Enter Emp no :: ");
	scanf("%d", &e1.empno);

	printf("\n Enter Name :: ");
	scanf("%s", e1.name);

	printf("\n Emp sal :: ");
	scanf("%f", &e1.sal);


	return ;
}
void DisplayEmpInfo()
{
	printf("\n Emp No  name   Sal \n");
	printf("=============================\n");
	printf("%-5d %-10s %-4.2f", e1.empno, e1.name,e1.sal );
	return;
}
