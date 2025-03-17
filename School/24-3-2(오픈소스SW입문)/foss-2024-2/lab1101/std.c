#include <stdio.h>

int main() {
	int a=0;
	fscanf(stdin, "%d", &a);
	fprintf(stdout, "%d-OUT: %d\n", __LINE__, a);
	fprintf(stderr, "%d-ERR: %d\n", __LINE__, -a);

	return a;
}
