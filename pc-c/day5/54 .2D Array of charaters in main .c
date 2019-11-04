#include <stdio.h>
#define NO 5
#define LEN 10
int main(void)
{
//	char name[10];
	//char names[5][10];
	char names[NO][LEN];
	int i;

	printf("\n Enter Names of students :: \n");
	for(i=0; i<NO; i++)
	{
		printf("\n names[%d] :: ", i);
		scanf("%s", &names[i]);
	}

	printf("\n names are :: ");
	for(i=0; i<NO; i++)
	{
		printf("\n names[%d] %-10s %u", i, names[i], &names[i]);
	}


	return 0;
}
