#include <stdio.h>
#pragma pack(1)
union result
{
	float per;
	char grade[5];
};
struct student
{
	int rollno;
	char name[10];
	int std;
	union result res;
};
int main(void)
{
	struct student s1;

	printf("\n Enter student info :: ");
	printf("\n Enter Rollno :: ");
	scanf("%d", &s1.rollno);
	printf("\n Enter name:: ");
	scanf("%s", s1.name);
	printf("\n Enter std :: ");
	scanf("%d", &s1.std);
	if(s1.std>4)
	{
		printf("\n Enter Per :: ");
		scanf("%f", &s1.res.per);
	}
	else
	{
		printf("\n Enter Grade :: ");
		scanf("%s", s1.res.grade);
	}

	printf("\n Student Info :: \n");
	printf("\n RollNo   Name   Std  Result\n");
	printf("%-6d%-10s%-6d ", s1.rollno, s1.name, s1.std);
	s1.std>4 ? printf("%-6.2f", s1.res.per) : printf("%-6s", s1.res.grade);

	printf("\n size of s1 =%d", sizeof(s1));

	return 0;
}
