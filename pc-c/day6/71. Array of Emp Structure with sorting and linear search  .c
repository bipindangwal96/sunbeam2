#include <stdio.h>
#define SIZE 3
struct emp
{
	int empno;
	char name[10];
	float sal;
};
void AcceptEmpInfo(struct emp e[], int size);
void DisplayEmpInfo(const struct emp e[], int size);
void SortEmpByEmpSalAsc(struct emp e[], int size);
struct emp* LinearSearchByEmpNo(struct emp e[], int size, int key);

int main(void)
{
	struct emp e1[SIZE], *ptr=NULL;
	int find;

	printf("\n Enter Emp Info :: \n");
	AcceptEmpInfo(e1, SIZE);

	printf("\n before sort Employees are :: ");
	DisplayEmpInfo(e1, SIZE);


	printf("\n Enter Empno to search :: ");
	scanf("%d", &find);

	ptr= LinearSearchByEmpNo(e1, SIZE, find);
	if(ptr==NULL)
		printf("\n %d emp no not found in array", find);
	else
	{
		printf("\n %d is found at %d position ", find,ptr-e1);
		DisplayEmpInfo(ptr,1);
	}

	SortEmpByEmpSalAsc(e1, SIZE);
	printf("\n after sort employee are :: ");
	DisplayEmpInfo(e1, SIZE);

	return 0;
}
void AcceptEmpInfo(struct emp e[], int size)
{
	int i;

	for(i=0; i<size; i++)
	{
		printf("\n Enter Emp No :: ");
		scanf("%d", &e[i].empno);
		printf("\n Enter Emp Name :: ");
		scanf("%s", e[i].name);
		printf("\n Enter Emp Sal :: ");
		scanf("%f", &e[i].sal);
	}

	return ;
}
void DisplayEmpInfo(const struct emp e[], int size)
{
	int i;
	printf("\n EmpNo  Name  Salary \n");
	for(i=0; i<size;i++)
	{
		printf("\n %-5d %-10s %5.2f", e[i].empno, e[i].name, e[i].sal);
	}
	return;
}
void SortEmpByEmpSalAsc(struct emp e[], int size)
{
	int i, j;
	struct emp temp;

	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size; j++)
		{
			//if(e[i]>e[j]) // error
			//if(e[i].sal > e[j].sal) // sort asc by sal
		    if(e[i].sal < e[j].sal) // sort desc by sal
			{
				temp= e[i];
				e[i]=e[j];
				e[j]=temp;
				// use function for swap
				// use macro for swap
			}
		}
	}
	return;
}
struct emp* LinearSearchByEmpNo(struct emp e[], int size, int key)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(e[i].empno==key)
			return &e[i];	 // if found return address
	}
	return NULL; // if not foun
}
