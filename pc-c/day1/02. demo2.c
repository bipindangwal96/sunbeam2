
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
int main(void)
{
	{
		short int no1=-9;
		if( no1> -10)
			printf("\n yes");
		else
			printf("\n no");

		short unsigned int no2=-9;
		printf("\n no2=%u\n", no2);
		if( no2> -10)
			printf("\n yes");
		else
			printf("\n no");

	}
	return 0;
	{
		int no1=300, no2=300, ans=0;
		ans= no1*no2;
		printf("\n ans=%d", ans);
	}
	{
		short int no1=300, no2=300, ans=65536;
		ans= no1*no2;
		printf("\n ans=%hd\n", ans);
	}
	{
		unsigned short int no1=65537;
		printf("%u", no1);
	}
	return 0;
	int no1=11,no2=3 , ans;
	float ans1=0.0;
	ans= no1/no2;
	printf("\n ans=%d", ans);

	ans1= no1/no2;
	printf("\n ans1=%f", ans1);

	ans1= (float )no1/no2;  // type casting
	printf("\n ans1=%f", ans1);

	ans1= no1/3.0f;
	printf("\n ans1=%.2f", ans1);
	printf("\n ans1=%.0f", ans1);

	return EXIT_SUCCESS;
}
