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
	int i, no;

	printf("\n how many employee you want :: ");
	scanf("%d", &no);

	ptr=(struct emp*)malloc(sizeof(struct emp)*no);
	//ptr=(struct emp*)calloc(no,sizeof(struct emp));
	if(ptr==NULL)
		printf("\n unbale to allocate memory for emp structure");
	else
	{
		printf("\n Emter Emp info :: ");

		/*for(i=0; i<no; i++)
		{
			printf("\n Enter Emp No :: ");
			scanf("%d", &ptr[i].empno);

			printf("\n Enter Emp Name :: ");
			scanf("%s", ptr[i].name);

			printf("\n Enter Emp sal :: ");
			scanf("%f", &ptr[i].sal);
		}*/

		printf("\n Employee Info :: \n");
		printf("\n empno  name   sal \n");
		for(i=0; i<no; i++)
			printf("\n %-5d%-10s%5.3f", ptr[i].empno, ptr[i].name, ptr[i].sal);

		free(ptr);
		ptr=NULL;
		printf("\n memory is freed ...");


	}

	return EXIT_SUCCESS;
}
