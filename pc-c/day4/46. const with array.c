#include <stdio.h>
int main(void)
{
	const int arr[]={11,22,33};
	int *ptr=&arr[0];

	//arr[0]=111; not allowed as arr is const
	//arr[1]=111;
	//arr[2]=111;
	printf("\n arr[0]=%d *ptr=%d", arr[0], *ptr);
	*ptr=111; // allowed as value of ptr is not constant
	printf("\n arr[0]=%d *ptr=%d", arr[0], *ptr);

	ptr=&arr[1]; //allowed as address of ptr is not const
	printf("\n arr[1]=%d *ptr=%d", arr[1], *ptr);
	return 0;
}
