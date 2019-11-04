#include <stdio.h>
#pragma pack(1)

struct test
{
	char a;
	short b;
	int c;
	double d;
	float e;
};

int main()
{
	struct test t1 = { 'A', 12, 1234, 1.23456, 2.3456 };
	struct test *p1 = &t1;
	int c;
	float e;
	printf("%c, %hd, %d, %lf, %f\n", t1.a, t1.b, t1.c, t1.d, t1.e);
	printf("%c, %hd, %d, %lf, %f\n", p1->a, p1->b, p1->c, p1->d, p1->e);
	c = p1->c;
	e = p1->e;
	printf("a = %c\n", *(char*)((char*)p1+0));
	//printf("a = %c\n", *((char*)p1+0));
	//printf("a = %c\n", *((char*)p1));
	printf("b = %hd\n", *(short*)((char*)p1+1));
	printf("c = %d\n", *(int*)((char*)p1+3));
	printf("d = %lf\n", *(double*)((char*)p1+7));
	printf("e = %f\n", *(float*)((char*)p1+15));
	return 0;
}













