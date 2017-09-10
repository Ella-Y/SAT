#include <stdio.h>

int main(void) {
	int arr[16][16] = { 0, };
	int result[16][16] = { 0, };
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= i; j++) scanf("%d", &arr[i][j]);
	}
	result[1][1] = arr[1][1];
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j <= i; j++) {
			result[i + 1][j] = result[i][j] + arr[i + 1][j] > result[i + 1][j] ? result[i][j] + arr[i + 1][j] : result[i + 1][j];
			result[i + 1][j + 1] = result[i][j] + arr[i + 1][j + 1] > result[i + 1][j + 1] ? result[i][j] + arr[i + 1][j + 1] : result[i + 1][j + 1];
		}
	}
	int max = 0;
	for (int i = 0; i < 16; i++) max = max > result[15][i] ? max : result[15][i];
	printf("%d\n",max);
}