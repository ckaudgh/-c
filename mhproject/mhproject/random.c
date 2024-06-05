#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void main()
{

	int i, j, num2[6];

	srand(time(NULL));
	for (i = 0; i < 6; i++) {
		num2[i] = (rand() % 45) + 1;
		for (j = 0; j < i; j++) {
			if (num2[i] == num2[j]) i--;
		}
	}
	printf("%d %d %d %d %d %d", num2[0], num2[1], num2[2], num2[3], num2[4], num2[5]);
}