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
int main(void)
{
	//struct emp is user defined data type
	// e1 is variable(object) of user defined data type struct emp
	//struct emp e1= {1};
	struct emp e1= {1, "rahul", 10000};
	 //struct emp e1; // garbage values


	struct emp *ptr= &e1;


	printf("\n size of e1=%d", sizeof(e1));
	printf("\n size of ptr=%d", sizeof(ptr));
	printf("\n &e1=%u &e1+1=%u", &e1, &e1+1);
	printf("\n ptr=%u ptr+1=%u", ptr, ptr+1);


	printf("\n Enter Emp no :: ");
	scanf("%d", &e1.empno);

	printf("\n Enter Name :: ");
	scanf("%s", e1.name);

	printf("\n Emp sal :: ");
	scanf("%f", &e1.sal);

	printf("\n=============================\n");
	printf("\n Emp No  name   Sal \n");
	printf("%-5d %-10s %-4.2f", e1.empno, e1.name,e1.sal );

	printf("\n=============================\n");

	printf("\n empno   name salary  using pointer  and -> operator \n");
	printf("%-5d %-10s %6.2f", ptr->empno, ptr->name, ptr->sal);

	printf("\n=============================\n");
	printf("\n empno   name salary  using pointer . opeartor \n");
	printf("%-5d %-10s %6.2f", (*ptr).empno, (*ptr).name, (*ptr).sal);

	printf("\n=============================\n");
	printf("\n\n\n");
	return EXIT_SUCCESS;
}
