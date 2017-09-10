#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int x, y;
int N;
int flag[200001] = { 0, };
int arr[100000][2];
void quickSort(int arr[][2], int left, int right);

int main(void) {
	scanf("%d", &N);
	for (int i = 0 ; i < N; i++) {
		scanf("%d %d", &x, &y);
		flag[x + 100000]++;
		arr[i][0] = x;
		arr[i][1] = y;
	}
	quickSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++) printf("%d %d\n", arr[i][0], arr[i][1]);
}

void quickSort(int arr[][2], int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2][0];
	int pivot2 = arr[(left + right) / 2][1];
	int temp[2];
	do {
		while (arr[i][0] <= pivot) {
			if (arr[i][0] == pivot && arr[i][1] == pivot2) break;
			if (arr[i][0] == pivot && arr[i][1] > pivot2) break;
			i++;
		}
		while (arr[j][0] >= pivot) {
			if (arr[j][0] == pivot && arr[j][1] == pivot2) break;
			if (arr[j][0] == pivot && arr[j][1] < pivot2) break;
			j--;
		}
		if (i <= j) {
			temp[0] = arr[i][0];
			temp[1] = arr[i][1];
			arr[i][0] = arr[j][0];
			arr[i][1] = arr[j][1];
			arr[j][0] = temp[0];
			arr[j][1] = temp[1];
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}