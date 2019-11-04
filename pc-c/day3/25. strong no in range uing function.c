#include<stdio.h>
int cnt;
int factorial (int n);
int IsStrongNo(int n);
void StrongNoInRange(int lowerLimit ,int upperLimit);
int main(void)
{
	// 1. check for factorial
	/*int no, ans;
	printf("\n Enter No :: ");
	scanf("%d", &no);

	ans= factorial(no);// no is actual argument
	printf("\n %d ! = %d",no, ans);
	*/

	//2. check no is strong or not
	/*int no;//, ans;
	printf("\n Enter No :: ");
	scanf("%d", &no);

	//ans= IsStrongNo(no);
	//if(ans==no)

	if(no==IsStrongNo(no))
		printf("\n %d is strong no", no);
	else
		printf("\n %d is not strong no", no);
		*/

	//3. strong no in range
	int llimit, ulimit;

	printf("\n Enter Lower Limit :: ");
	scanf("%d", &llimit);
	printf("\n Enter Upper Limit :: ");
	scanf("%d", &ulimit);

	printf("\n strong no with in range %d  to %d :: \n", llimit, ulimit);
	StrongNoInRange(llimit, ulimit);

	printf("\n cnt=%d", cnt);
	return 0;
}
int IsStrongNo(int n)
{
	int rem, sum;
	rem=sum=0;
	while(n!=0)
	{
		rem= n%10;
		n/=10; // n=n/10;
		sum= sum+factorial(rem);
	}
	return sum;
}
int factorial (int n)
{
	cnt++;
	int counter, fact;
	for(counter=fact=1;counter<=n; ++counter )
	{
		fact= fact*counter;
	}
	return fact;
}
void StrongNoInRange(int lowerLimit ,int upperLimit)
{
	int no;

	for(no=lowerLimit; no<=upperLimit; no++)
	{
		if(no==IsStrongNo(no))
			printf("\n %d", no);
	}
	return;
}

