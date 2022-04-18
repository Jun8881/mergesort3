#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
* ListU[a...b](총 m개) + ListV[b+1...c](총 n개)
* 리스트U는 i개, 리스트V는 j개의 인덱스를 가짐
*/
void merge(int arr[], int a, int b, int c) {
	//int f, int h, int m, int U[], int V[], int S[] 로하면 매개 변수가 너무 많다는 오류.

	int i = a, j = b + 1, k = a;
	int m = b - a + 1;
	int n = c - b; //(c - (b + 1) + 1)
	int U[50], V[50];


	while (i <= b && j <= c) {
		if (U[i] <= V[j]) {	//리스트U에 인덱스 추가
			arr[k] = U[i];
			i++;
		}
		else {
			arr[k] = V[j];	//리스트V에 인덱스 추가
			j++;
		}
		k++;

	}

	//리스트를 다 쓴 경우 남은 인덱스들을 S에 넣기
	while (i <= m) {
		arr[k] = U[i];
		i++;
		k++;
	}
	
	while (j <= n) {
		arr[k] = V[j];
		for (k = a; k <= c; k++) {
			arr[k] = V[j];
			j++;
			k++;
		}
	}
	
}

void mergeSort(int arr[], int a, int c) {


	if (a < c) {
		int b = (a + c) / 2;

		mergeSort(arr, a, b);
		mergeSort(arr, b + 1, c);
		merge(arr, a, b, c);
	}

}


int main() {
	double str, fin;

	int i1;
	int arr1[100];
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int i;
	str = (double)clock() / CLOCKS_PER_SEC;

	srand((int)time(NULL));
	for (i1 = 0; i1 < 100; i1++) {
		arr1[i1] = (rand() % 1000 + 1);
	}

	printf("기존 리스트: \n");
	
	for (i = 0; i < size1; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	
	mergeSort(arr1, 0, size1 - 1);

	fin = (((double)clock()) / CLOCKS_PER_SEC);

	printf("merge sorting 이후 리스트: \n");
	for (i = 0; i < size1; i++) {
		printf("%d", arr1[i]);
	}
	printf("\n");

	printf("실행시간: %fms", (fin-str));


	return 0;
}