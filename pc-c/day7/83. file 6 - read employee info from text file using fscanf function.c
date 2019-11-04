#include <stdio.h>
struct emp
{
	int empno;
	char name[10];
	float sal;
};
void DisplayEmpInfo(const struct emp *e);
int main(void)
{
	struct emp e1;
	int cnt=0;
	FILE *fpEmpRead=NULL;

	if( (fpEmpRead=fopen("empinfo.txt","r"))==NULL)
		printf("\n unable to read data from file");
	else
	{
		// read 1st record using fscanf fun from file

	/*	printf("\n EmpNo Name Sal ");
		printf("\n ================================\n");
		fscanf(fpEmpRead,"%d\t%s\t%f\n", &e1.empno, e1.name, &e1.sal);
		DisplayEmpInfo(&e1);*/

		// to read all records from file
		printf("\n EmpNo Name Sal ");
		printf("\n ================================\n");
		while(fscanf(fpEmpRead,"%d\t%s\t%f\n", &e1.empno, e1.name, &e1.sal)!=EOF)
		{
				DisplayEmpInfo(&e1);
				cnt++;
		}
		printf("\n %d records is read from file", cnt);
		fclose(fpEmpRead);
	}

	return 0;
}
void DisplayEmpInfo(const struct emp *e)
{
	printf("%-6d%-10s%6.2f\n", e->empno, e->name, e->sal);
	return;
}
