#include <stdio.h>
#include <string.h>
#define LEN 40
int main(void)
{
	// string
	char city1 []="pune"; //'\0' //added at the end by compiler
	char city2 []={'k','a','r','a','d','\0'};
	char city3 [LEN]="karad";
	char city4 [LEN]={'p','u','n','e', '\0'};
// array of char
	char city5 [LEN]={'p','u','n','e'};


	printf("\n length of %s is %d", city1,strlen(city1));
	printf("\n sizeof of %s is %d", city1, sizeof(city1));

	printf("\n length of %s is %d", city2,strlen(city2));
	printf("\n sizeof of %s is %d", city2, sizeof(city2));

	printf("\n length of %s is %d", city3,strlen(city3));
	printf("\n sizeof of %s is %d", city3, sizeof(city3));

	printf("\n length of %s is %d", city4,strlen(city4));
	printf("\n sizeof of %s is %d", city4, sizeof(city4));


	printf("\n Enter city4 :: ");
	//scanf("%s", city4);// city4 is name of array i.e base address
	// scan upto space

	//gets(city4); // scan upto new line char \n

	//scanf("%[^\n]s", city4); // scan upto new line char \n
    //scanf("%[^.]s", city4); // scan upto . multiple lines
	//scanf("%[A-Z]", city4);// scan upto capital letters
	//scanf("%[^a-z]", city4);// scan upto capital letters
	//scanf("%[a-z]", city4);// scan upto small letters
	//scanf("%[^A-Z]", city4);// scan upto small letters
	//scanf("%[0-9]s", city4); // scan upto digits
	scanf("%[^0-9]s", city4); // scan upto letters
	printf("city4=%s", city4);


	printf("\n city4 = %s", city4);
	return 0;
}
