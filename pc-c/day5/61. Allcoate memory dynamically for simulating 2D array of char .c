#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(void)
{
	char **arr=NULL, name[30], *temp=NULL;
	int i, j, no;

	printf("\n Enter how many names you want :: ");
	scanf("%d", &no);

	arr= (char**)malloc(sizeof(char*)*no);

	printf("\n Enter Your names :: ");

	for(i=0; i<no; i++)
	{
		printf("\n Enter name [%d] ::", i);
		scanf("%s",name); // accept name
		arr[i]= (char*)malloc((strlen(name)+1)*sizeof(char));
		// allocate memory dynamically
		strcpy(arr[i], name); // copy data from name
	}

	printf("\n names before sorting :: \n");

	for(i=0; i<no; i++)
	{
		printf("\n &arr[%d] = %u arr[%d] = %u  arr[%d] =%-10s  *arr[%d] =%c ", i, &arr[i], i, arr[i], i, arr[i], i, *arr[i]);
	}

	//sorting

	for(i=0; i<no; i++)
	{
		for(j= i+1; j<no ; j++)
		{
			if(strcmp(arr[i], arr[j])>0)
			{
				temp= arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}



	printf("\n names after sorting :: \n");
	for(i=0; i<no; i++)
	{
		printf("\n &arr[%d] = %u arr[%d] = %u  arr[%d] =%-10s  arr[%d] =%c ", i, &arr[i], i, arr[i], i, arr[i], i, *arr[i]);
	}

	// to free the memory
	for(i=0; i<no; i++)
	{
		free(arr[i]); // free memory for cols
		arr[i]=NULL;
	}
	free(arr); // free memory for rows
	arr=NULL;
	printf("\n memory is freed \n");
	return EXIT_SUCCESS;
}
