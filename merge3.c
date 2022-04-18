#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
* ListU[a...b](�� m��) + ListV[b+1...c](�� n��)
* ����ƮU�� i��, ����ƮV�� j���� �ε����� ����
*/
void merge(int arr[], int a, int b, int c) {
	//int f, int h, int m, int U[], int V[], int S[] ���ϸ� �Ű� ������ �ʹ� ���ٴ� ����.

	int i = a, j = b + 1, k = a;
	int m = b - a + 1;
	int n = c - b; //(c - (b + 1) + 1)
	int U[50], V[50];


	while (i <= b && j <= c) {
		if (U[i] <= V[j]) {	//����ƮU�� �ε��� �߰�
			arr[k] = U[i];
			i++;
		}
		else {
			arr[k] = V[j];	//����ƮV�� �ε��� �߰�
			j++;
		}
		k++;

	}

	//����Ʈ�� �� �� ��� ���� �ε������� S�� �ֱ�
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

	printf("���� ����Ʈ: \n");
	
	for (i = 0; i < size1; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	
	mergeSort(arr1, 0, size1 - 1);

	fin = (((double)clock()) / CLOCKS_PER_SEC);

	printf("merge sorting ���� ����Ʈ: \n");
	for (i = 0; i < size1; i++) {
		printf("%d", arr1[i]);
	}
	printf("\n");

	printf("����ð�: %fms", (fin-str));


	return 0;
}