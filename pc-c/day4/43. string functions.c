#include <stdio.h>
#include <string.h>
#define LEN 40
int MenuChoice();
int main(void)
{
	char dest[LEN], src[LEN], find, *ptr=NULL;
	int choice, ans1;
	size_t ans;

	do
	{
		choice= MenuChoice();

		if(choice>=1 && choice<=2)
		{
			printf("\n enter src ::");
			scanf("%*c"); // getchar();
			gets(src);
		}
		else if(choice>=3 && choice<=7)
		{
			printf("\n enter src ::");
			scanf("%*c");
			gets(src);
			printf("\n enter dest ::");
			gets(dest);
		}

		switch(choice)
		{
			case 1 : // string length
					ans= strlen(src);
					printf("\n length of %s =%d", src, ans);

					break;
			case 2 : // search char in string (linear search)
					printf("\n Enter char to find :: ");
					scanf("%c", &find);
					ptr=strchr(src, find);
					if(ptr==NULL)
						printf("\n %c is not found in %s", find, src);
					else
						printf("\n %c is found at %d location in %s", find, ptr-src, src);
					break;
			case 3 : // string copy
					ptr=strcpy(dest, src);
					printf("\n using pointer ptr=%s", ptr);
					printf("\n using dest parameter =%s", dest);
					break;
			case 4 : // string concate
					ptr=strcat(dest, src);
					printf("\n using pointer=%s", ptr);
					printf("\n using dest parameter =%s", dest);

					break;
			case 5 : // string compare

					ans1= strcmp(src, dest);
					if(ans1==0)
						printf("\n %s is equal to %s", src, dest);
					else if( ans1>0)
						printf("\n %s is grater than %s", src, dest);
					else if(ans1<0)
						printf("\n %s is smaller than %s", src, dest);

					break;
			case 6 : // string comapre by ingoring cases
					ans1= strcasecmp(src, dest);
					if(ans1==0)
						printf("\n %s is equal to %s", src, dest);
					else if( ans1>0)
						printf("\n %s is grater than %s", src, dest);
					else if(ans1<0)
						printf("\n %s is smaller than %s", src, dest);

					break;
			case 7: // search substring in string
					ptr=strstr(src, dest);
					if(ptr==NULL)
						printf("\n %s is not found in %s", dest, src);
					else
						printf("\n %s is found in %s at %d lcoation ", dest, src, ptr-src);
					break;
			default : printf("\n invalid choice :: ");
					continue;
		}
			printf("\n Enter 1 to continue or 0 to exit ::  ");
			scanf("%d", &choice);

	}while(choice !=0 );
	return 0;
}
int MenuChoice()
{
	int choice;
	printf("\n 1. strlen \n 2.strchr \n 3. strcpy \n 4. strcat ");
	printf("\n 5. strcmp \n 6.strcasecmp \n 7. strstr \n 8. Exit ");
	printf("\n Enter Your choice :: ");
	scanf("%d", &choice);
	return choice;
}
//char *strstr(const char * string , const char * substring);

//return 11; // return type int
//return 11.2; // return type double
//return 11.2f; // return type float

//return 'A'; // return type char
//return "ABC"; // return type char*

