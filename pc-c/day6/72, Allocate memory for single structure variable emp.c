#include <stdio.h>
#include <stdlib.h>
struct emp
{
	int empno;
	char name[10];
	float sal;
};
int main(void)
{
	struct emp *ptr=NULL;
	ptr=(struct emp*)malloc(sizeof(struct emp)*1);
	if(ptr==NULL)
		printf("\n unbale to allocate memory for emp structure");
	else
	{
		printf("\n Emter Emp info :: ");
		printf("\n Enter Emp No :: ");
		scanf("%d", &ptr->empno);

		printf("\n Enter Emp Name :: ");
		scanf("%s", ptr->name);

		printf("\n Enter Emp sal :: ");
		scanf("%f", &ptr->sal);

		printf("\n Employee Info :: \n");
		printf("%-5d%-10s%5.3f", ptr->empno, ptr->name, ptr->sal);

		free(ptr);
		ptr=NULL;
		printf("\n memory is freed ...");


	}

	return EXIT_SUCCESS;
}
