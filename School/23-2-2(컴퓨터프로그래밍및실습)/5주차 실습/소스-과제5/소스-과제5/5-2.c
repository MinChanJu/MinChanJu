#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6

void throw_dice(void);

int main(void) {
	srand((unsigned)time(NULL));
	throw_dice();
}

void throw_dice(void)
{
	static int one, two, three, four, five, six, call_count = 0;
	int i;
	while (call_count < 100) {
		i = rand() % MAX;
		call_count++;
		if (i == 0) six++;
		else if (i == 5) five++;
		else if (i == 4) four++;
		else if (i == 3) three++;
		else if (i == 2) two++;
		else if (i == 1) one++;
	}
	printf("1: %d\n", one);
	printf("2: %d\n", two);
	printf("3: %d\n", three);
	printf("4: %d\n", four);
	printf("5: %d\n", five);
	printf("6: %d", six);
}