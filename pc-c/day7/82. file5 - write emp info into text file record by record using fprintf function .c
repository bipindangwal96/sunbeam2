#include <stdio.h>
struct emp
{
	int empno;
	char name[10];
	float sal;
};
void AcceptEmpInfo(struct emp *e);
int main(void)
{
	struct emp e1;
	FILE *fpEmpWrite=NULL;

	if( (fpEmpWrite=fopen("empinfo.txt","a"))==NULL)
		printf("\n unable to open file");
	else
	{
		printf("\n Enter Emp Info :: \n");
		AcceptEmpInfo(&e1);
		// write emp data in text file
		fprintf(fpEmpWrite,"%d\t%s\t%f\n", e1.empno, e1.name, e1.sal);
		printf("\n record is added to file");
	}

	return 0;
}
void AcceptEmpInfo(struct emp *e)
{
	fprintf(stdout,"\n Enter Emp No :: ");
	fscanf(stdin,"%d", &e->empno);

	fprintf(stdout,"\n Enter Emp Name :: ");
	fscanf(stdin,"%s", e->name);

	do
	{
		fprintf(stdout,"\n Enter Emp sal :: ");
		fscanf(stdin,"%f", &e->sal);

	}while(e->sal<=0);

	return;
}
