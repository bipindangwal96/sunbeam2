#include <stdio.h>
struct test {
	int a; // 4
	char b; // 1 (+3)
	int c; // 4
	char d; // 1 (+3)
	int e; // 4
	char f; // 1 (+3)
	int g; // 4
	char h; // 1 (+3)
};
int main() {
	struct test t;
	printf("%lu\n", sizeof(struct test));
	printf("&t : %p\n", &t);
	printf("&t.a : %p\n", &t.a);
	printf("&t.b : %p\n", &t.b);
	printf("&t.c : %p\n", &t.c);
	printf("&t.d : %p\n", &t.d);
	printf("&t.e : %p\n", &t.e);
	printf("&t.f : %p\n", &t.f);
	printf("&t.g : %p\n", &t.g);
	printf("&t.h : %p\n", &t.h);
	return 0;
}













