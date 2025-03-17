#include <stdio.h>

int main() {
	int a=0;
	fscanf(stdin, "%d", &a);
	fprintf(stdout, "%d\n", a);
	fprintf(stderr, "%d\n", -a);

	return a;
}
