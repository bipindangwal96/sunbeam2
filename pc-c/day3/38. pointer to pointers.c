#include<stdio.h>
int main(void)
{
	int x=10; // variable
	int *px= &x; // pointer
	int **ppx= &px; // pointer to pointer

	printf("\n x=%d *(&x)=%d *px=%d **ppx=%d", x, *(&x), *px, **ppx);
	printf("\n &x=%u &px=%u &ppx=%u", &x, &px, &ppx);
	printf("\n px=%u ppx=%u ", px, ppx);

	printf("\n size of px=%d", sizeof(px));
	printf("\n size of ppx=%d", sizeof(ppx));


	*px=20;
	printf("\n x=%d *(&x)=%d *px=%d **ppx=%d", x, *(&x), *px, **ppx);

	**ppx=30;
	printf("\n x=%d *(&x)=%d *px=%d **ppx=%d", x, *(&x), *px, **ppx);
	return 0;
}

