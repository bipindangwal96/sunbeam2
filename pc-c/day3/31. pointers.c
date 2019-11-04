#include<stdio.h>
int main(void)
{
	printf("\n int data type :: \n");
	{
	int z=3;
	//int *z_ptr=&z;
	//or
	int *z_ptr=NULL;
	z_ptr=&z;

	printf("\n z=%d *(&z)=%d *z_ptr=%d",z, *(&z), *z_ptr);
	printf("\n &z=%u z_ptr=%u &z_ptr=%u", &z, z_ptr, &z_ptr);
	printf("\n &z=%p z_ptr=%p &z_ptr=%p", &z, z_ptr, &z_ptr);
	*z_ptr=10;
	printf("\n z=%d *(&z)=%d *z_ptr=%d",z, *(&z), *z_ptr);
	printf("\n size of z_ptr=%d", sizeof(z_ptr));
	printf("\n z_ptr=%u z_ptr+1=%u", z_ptr, z_ptr+1);
	printf("\n z_ptr=%u z_ptr+5=%u", z_ptr, z_ptr+5);
	printf("\n z_ptr=%u z_ptr-5=%u", z_ptr, z_ptr-5);
	//printf("\n z_ptr=%u z_ptr*5=%u", z_ptr, z_ptr*5); //error
	//	printf("\n z_ptr=%u z_ptr/5=%u", z_ptr, z_ptr/5);
	}
	printf("\n========================================\n");

	printf("\n float data type :: \n");
	{
		float z=3.142;
		//float *z_ptr=&z;
		//or
		float *z_ptr=NULL;
		z_ptr=&z;

		printf("\n z=%f *(&z)=%f *z_ptr=%f",z, *(&z), *z_ptr);
		printf("\n &z=%u z_ptr=%u &z_ptr=%u", &z, z_ptr, &z_ptr);
		printf("\n &z=%p z_ptr=%p &z_ptr=%p", &z, z_ptr, &z_ptr);
		*z_ptr=4.23;
		printf("\n z=%f *(&z)=%f *z_ptr=%f",z, *(&z), *z_ptr);
		printf("\n size of z_ptr=%d", sizeof(z_ptr));
		printf("\n z_ptr=%u z_ptr+1=%u", z_ptr, z_ptr+1);
		printf("\n z_ptr=%u z_ptr+5=%u", z_ptr, z_ptr+5);
		printf("\n z_ptr=%u z_ptr-5=%u", z_ptr, z_ptr-5);
	}
	printf("\n========================================\n");

	printf("\n char data type :: \n");
	{
	char z='A';
	//char *z_ptr=&z;
	//or
	char *z_ptr=NULL;
	z_ptr=&z;

	printf("\n z=%c *(&z)=%c *z_ptr=%c",z, *(&z), *z_ptr);
	printf("\n &z=%u z_ptr=%u &z_ptr=%u", &z, z_ptr, &z_ptr);
	printf("\n &z=%p z_ptr=%p &z_ptr=%p", &z, z_ptr, &z_ptr);
	*z_ptr='B';
	printf("\n z=%c *(&z)=%c *z_ptr=%c",z, *(&z), *z_ptr);
	printf("\n size of z_ptr=%d", sizeof(z_ptr));
	printf("\n z_ptr=%u z_ptr+1=%u", z_ptr, z_ptr+1);
	printf("\n z_ptr=%u z_ptr+5=%u", z_ptr, z_ptr+5);
	printf("\n z_ptr=%u z_ptr-5=%u", z_ptr, z_ptr-5);
	}
	printf("\n========================================\n");

	return 0;
}



