#include<stdio.h>
//1. function decl or proto type of function
//output function_name(input);
//return_type function_name(datatype var1);
int addition(int n1, int n2);
int main(void)
{
	int no1, no2, ans=0;
	printf("\n Enter No1 :: ");
	scanf("%d", &no1);

	printf("\n Enter No2 :: ");
	scanf("%d", &no2);

	ans=addition(no1, no2);// 3. function call
	// no1 and no2 are called as actual arguments
	printf("\n %d + %d =%d", no1, no2, ans);
	return 0;
}
// 2. function defination  -->> logic
// n1 and n2 formal arugments
int addition(int n1, int n2)
{
	int temp=0;
	temp=n1+n2;
	return temp, n1,n2, n1*n2;
}
//return 10; // return type int
//return 10.2; // return type double
//return 10.2f; // return type float
//return 10.2F; // return type float
//return 'A'; // return type char
//return "sunbeam"; // return type char*
//return;  return type void

