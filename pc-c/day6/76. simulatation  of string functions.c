#include <stdio.h>
#include<string.h>
#define LEN 40
int MenuOperations();
//size_t mystrlen(char s[]);
size_t mystrlen(const char *s);
char* mystrchr(const char *s, int find);
char* mystrcpy(char *d, const char *s);
char* mystrcat(char *d, const char *s);
int mystrcmp(const char *s1,const char *s2 );
char* mystrupr(char *s);
int main( void )
{
	char src[LEN],dest[LEN], *ptr=NULL, find;
	int choice, ans1;
	unsigned int ans;
	do
	{
		choice= MenuOperations();
		if((choice>=1 && choice<=2) ||(choice>=8 && choice<=10))
		{
			printf("\n enter src :: ");
			scanf("%*c");//getchar();
			gets(src);
		}
		else if(choice>=3 && choice<=7)
		{
			printf("\n enter src :: ");
			scanf("%*c");
			gets(src);
			printf("\n enter dest :: ");
			gets(dest);
		}


		switch(choice)
		{
			case 1: //string length
					ans= mystrlen(src);
					printf("\n length of %s  is %d", src, ans);
					break;
			case 2 :// serach char in string
					printf("\n Enter Char to search :: ");
					scanf("%c", &find);
					ptr= mystrchr(src, find);
					if(ptr==NULL)
						printf("%c is not found in %s", find, src);
					else
						printf("%c is  found in %s at  %d position", find, src, ptr-src);
					break;
			case 3:// string copy
					ptr= mystrcpy(dest, src);
					//strcpy(dest, src);
					printf("\n using out parameter dest =%s",dest );
					printf("\n using return statement= %s ",ptr );
					break;
			case 4: // string concate
					ptr= mystrcat(dest, src);
					printf("\n using out parameter dest =%s",dest );
					printf("\n using return statement= %s ",ptr );
					break;
			case 5:// string compare
					ans1=mystrcmp(src, dest);
					if(ans1>0)
						printf("%s is bigger than %s ", src,dest );
					else if( ans1<0)
						printf("%s is smaller than %s ", src ,dest );
					else if(ans1==0)
						printf("%s is equal to %s ", src ,dest );

					break;
			case 6:// string compare by ignoring case
					ans1=strcasecmp(src, dest);
					if(ans1>0)
						printf("%s is bigger than %s ", src,dest );
					else if( ans1<0)
						printf("%s is smaller than %s ", src ,dest );
					else if(ans1==0)
						printf("%s is equal to %s ", src ,dest );
					break;
			case 7:// search sub string in string
					ptr= strstr(src, dest);
					if( ptr==NULL)
						printf("%s is not found  in %s", dest, src);
					else
						printf("%s is found  in %s at %d location", dest, src, ptr-src );
					break;
			case 8:// upper case
					ptr= mystrupr(src);
					printf("\n using out parameter dest =%s",src );
					printf("\n using return statement= %s ",ptr );
					break;

		}

	    //char *strstr(const char *string, const char *substring);

		printf("\n Enter 1 to continue or 0 to Exit :: ");
		scanf("%d", &choice);

	}while(choice!=0);
	return 0;
}
char* mystrupr(char *s)
{
	int index;
	for(index=0; *(s+index)!='\0'; index++)
	{
		if(*(s+index)>=97 && *(s+index)<=122 )
		{
			*(s+index)-=32; //*(s+index)= *(s+index)-32;
		}
	}
	return s;

}
int mystrcmp(const char *s1,const char *s2 )
{
	int index;
	for(index=0; *(s1+index)!='\0' || *(s2+index)!='\0' ; index++)
	{
		if( *(s1+index)!= *(s2+index)) // if( s1[index]!= s2[index])
			return *(s1+index)- *(s2+index); // return s1[index]-  s2[index];
	}
	return 0;
}
char* mystrcat(char *d, const char *s)
{
	int indexi, indexj;
	for(indexi=0; *(d+indexi)!='\0'; indexi++); // goto end of dest string

	for(indexj=0; *(s+indexj)!='\0'; indexj++)
	{
		*(d+indexi+indexj)= *(s+indexj);//d[indexi+indexj]= s[indexj];
	}
	d[indexi+ indexj]='\0'; // copy \0 after d+s
	return d;
}
char* mystrcpy(char *d, const char *s)
{
	int index;
	for( index=0; *(s+index)!='\0'; ++index)
	{
		*(d+index)= *(s+index); // d[index]= s[index];
	}
	*(d+index)='\0';//copy '\0' at end
	return d;
}
//char* mystrchr(const char s[], int find)
char* mystrchr(const char *s, int find)
{
	int index;
	index=0;
	while(*(s+index)!='\0') // while(s[index]!='\0')
	{
		if( *(s+index)==find) //if( s[index]==find)
			return (s+index);//return &s[index];
		index++;
	}
	return NULL;
}

size_t mystrlen(const char *s)
{
	unsigned int index;
/*	index=0;
	while(*(s+index)!='\0' )
	{
		index++;
	}
	return index;*/

	//for(index=0; s[index]!='\0'; ++index);
	for(index=0; s[index]!='\0'; ++index)
	{

	}
	return index;
}

int MenuOperations()
{
	int choice;
	printf("\n 1. strlen \n 2. strchr \n 3. strcpy \n 4. strcat ");
	printf("\n 5. strcmp \n 6. stcasecmp / strcmpi \n 7. strstr \n 8. strupr \n 9. strlwr \n 10. strrev 0. Exit  \n");

	printf("\n Enter Your Choice :: ");
	scanf("%d", &choice);

	return choice;
}

// return 10; // int
// return 10.2; // double
// return "sunbeam"; char*
