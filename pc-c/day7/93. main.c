#include <stdio.h>
int main(void)
{
	#line 0

	printf("\n date =%s", __DATE__);
	printf("\n time =%s", __TIME__);
	printf("\nfile name =%s", __FILE__);
	printf("\n Line =%d", __LINE__);


	return 0;
}
