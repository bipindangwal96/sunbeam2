#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int index, *ptr, no;
	printf("\n Enter How many elements you want :: \n");
	scanf("%d", &no);

	ptr= (int*)malloc(sizeof(int)*no);
	if(ptr==NULL)
		printf("\n unable to allocate memory");
	else
	{
		printf("\n Enter elements of array :: ");
		for(index=0; index<no; index++)
		{
			printf("\n ptr[%d] :: ", index);
			//scanf("%d", (ptr+index)); // pointer notations
			//scanf("%d", (index+ptr));
			//scanf("%d", &ptr[index]); // array notation
			scanf("%d", &index[ptr]);
		}
		printf("\n ptr=%u &ptr=%u\n", ptr, &ptr);
		printf("\n Elements of array :: \n");
		for(index=0; index<no; ++index)
		{
			// pointer notations
			//printf("\n *(ptr+%d) %5d [%u]", index, *(ptr+index), (ptr+index));
		   // printf("\n *(ptr+%d) %5d [%u]", index, *(index+ptr), (index+ptr));
			// array notation
			//printf("\n ptr[%d]  %d [%u]", index, ptr[index], &ptr[index]);
			printf("\n %d[ptr]  %5d [%u]", index, index[ptr], &index[ptr]);
		}
		free(ptr);
		ptr=NULL;
		printf("\n Memory is freed\n");
	}
	return EXIT_SUCCESS;
}
