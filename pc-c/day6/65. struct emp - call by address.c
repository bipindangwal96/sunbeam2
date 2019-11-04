#include <stdio.h>
#include <stdlib.h>
#pragma pack(1) // to remove slack bytes
// struct decl

struct emp
{
	int empno;
	char name[10];
	float sal;
};
void AcceptEmpInfo(struct emp *e); // size of e = 4 to 8 bytes
//void DisplayEmpInfo(struct emp e); // size of e = 18
void DisplayEmpInfo(const struct emp *e); // size of e = 4 or 8
int main(void)
{
	struct emp e1;

	printf("\n Enter info of employee :: ");
	AcceptEmpInfo(&e1);

	printf("\n Employee info :: \n");
	DisplayEmpInfo(&e1);

	printf("\n\n\n");
	return EXIT_SUCCESS;
}
void AcceptEmpInfo(struct emp *e)
{
	printf("\n Enter Emp no :: ");
	scanf("%d", &e->empno);

	printf("\n Enter Name :: ");
	scanf("%s", e->name);

	printf("\n Emp sal :: ");
	scanf("%f", &e->sal);

	return ;
}
void DisplayEmpInfo(const struct emp  *e)
{
	//e->sal=0; //error as e is constant
	printf("\n Emp No  name   Sal \n");
	printf("=============================\n");
	printf("%-5d %-10s %-4.2f", e->empno, e->name,e->sal );
	return;
}
