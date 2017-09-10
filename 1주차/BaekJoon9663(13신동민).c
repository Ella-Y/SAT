#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int n, *col, answer;

int promising(int i)
{
	int k, check;

	k = 1, check = 1;
	while (k < i && check) {
		if (col[k] == col[i] || abs(col[i] - col[k]) == i - k)
			check = 0;
		k++;
	}

	return check;
}

void nqueen(int i)
{
	int j;

	if (promising(i)) {
		if (i == n) {
			answer++;
		}
		else {
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				nqueen(i + 1);
			}
		}
	}
}

int main(void)
{
	scanf("%d", &n);

	col = (int *)malloc(sizeof(int) * (n + 1));
	col[1] = 1;
	nqueen(0);

	printf("%d\n", answer);
	return 0;
}