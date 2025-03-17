#define CRT_SECURE_NO_WARNNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STUDENT 10
#define TEST 3

void initialize_score(int a[][TEST], int row, int col);
void print_score(int a[][TEST], int row, int col);
void find_max_min(int score[][TEST], int row, int col);

int main(void) {
	int score[STUDENT][TEST];

	initialize_score(score, STUDENT, TEST);
	print_score(score, STUDENT, TEST);
	find_max_min(score, STUDENT, TEST);

	return 0;
}

void initialize_score(int a[][TEST], int row, int col) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] = rand() % 100 + 1;
		}
	}
}

void print_score(int a[][TEST], int row, int col) {
	for (int i = 0; i < row; i++) {
		printf("학생 %02d의 성적:", i + 1);
		for (int j = 0; j < col; j++) {
			printf("%02d\t", a[i][j]);
		}
		printf("\n");
	}
}

void find_max_min(int score[][TEST], int row, int col) {
	int max, min;
	for (int i = 0; i < col; i++) {
		max = 0;
		min = 100;
		for (int j = 0; j < row; j++) {
			if (max < score[j][i]) {
				max = score[j][i];
			}
			if (min > score[j][i]) {
				min = score[j][i];
			}
		}
		printf("시험 %d의 최고, 최저 점수 =%d\t%d\n", i + 1, max, min);
	}
}