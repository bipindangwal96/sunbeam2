#include <stdio.h>
struct test {
	int a; // 4
	char b; // 1 (+3)
	short c; // 2
};
int main() {
	struct test t;
	printf("%lu\n", sizeof(struct test));
	printf("&t : %p\n", &t);
	printf("&t.a : %p\n", &t.a);
	printf("&t.b : %p\n", &t.b);
	printf("&t.c : %p\n", &t.c);
	return 0;
}













