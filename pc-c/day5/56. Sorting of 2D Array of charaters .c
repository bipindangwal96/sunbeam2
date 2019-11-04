#include <stdio.h>
#include<string.h>
#define NO 5
#define LEN 10
void DisplayNames(const char n[][LEN], int no);
int main(void)
{
//	char name[10];
	//char names[5][10];
	char names[NO][LEN], temp[LEN];
	int i, j;

	printf("\n Enter Names of students :: \n");
	for(i=0; i<NO; i++)
	{
		printf("\n names[%d] :: ", i);
		scanf("%s", &names[i]);
	}

	printf("\n names are :: ");
	DisplayNames(names, NO);
	/*for(i=0; i<NO; i++)
	{
		printf("\n names[%d] %-10s %u", i, names[i], &names[i]);
	}*/

	for(i=0; i<NO; i++)
	{
		for(j=i+1; j<NO; j++)
		{
			printf("\n names[%d] %s \t names[%d] %s \n", i, names[i], j, names[j]);
			//if(strcmp(names[i], names[j])>0) // asc
			if(strcmp(names[i], names[j])<0) // desc
			{
				strcpy(temp, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp);
			}
		}
		if(i<NO-1)
			printf("\n pass %d ", i+1);
	}

	printf("\n names after  sort are :: \n");
	DisplayNames(names, NO);
	/*for(i=0; i<NO; i++)
	{
		printf("\n names[%d] %-10s %u", i, names[i], &names[i]);
	}*/

	return 0;
}
void DisplayNames(const char n[][LEN], int no)
{
	int i;
	for(i=0; i<no; i++)
	{
		printf("\n n[%d] %-10s %u", i, n[i], &n[i]);
	}
	return;
}
