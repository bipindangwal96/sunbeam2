#include <stdio.h>
struct emp
{
	int empno;
	char name[10];
	float sal;
};
void ReadEmpDataFromTextFile();
void WriteEmpDataIntoTextFile();
void AcceptEmpInfo(struct emp *e);
void DisplayEmpInfo(const struct emp *e);
int MenuOperations();
int main(void)
{
	int choice;

	do
	{
		choice= MenuOperations();
		switch(choice)
		{
			default : printf("\n invalid choice :: ");
				continue;

			case 1: // add new record
					WriteEmpDataIntoTextFile();
					break;
			case 2 :// print all records
					ReadEmpDataFromTextFile();
					break;
			case 0:
					return 0; // exit(0);

		}

		printf("\n Enter 1 to continue  or 0 to exit :: ");
		scanf("%d", &choice);

	}while(choice!=0);
	return 0;
}
void WriteEmpDataIntoTextFile()
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
		fprintf(fpEmpWrite,"\n%d\t%s\t%f", e1.empno, e1.name, e1.sal);
		printf("\n record is added to file");
		fclose(fpEmpWrite);
	}
	return;
}

void ReadEmpDataFromTextFile()
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
		return;
}
void DisplayEmpInfo(const struct emp *e)
{
	printf("%-6d%-10s%6.2f\n", e->empno, e->name, e->sal);
	return;
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
int MenuOperations()
{
	int choice;
	printf("\n 1. Add EmpInfo into File ");
	printf("\n 2. display EmpInfo from File \n 0. Exit ");

	printf("\n Enter Your Choice :: ");
	scanf("%d", &choice);

	return choice;
}

