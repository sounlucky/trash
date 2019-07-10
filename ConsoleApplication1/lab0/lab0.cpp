#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>

// input a single number
int input_int() {
	int res;
	printf("\t");
	scanf("%d", &res);
	return res;
}

int main() {
	// input dimensions
	printf("input a[n] array: \n");
	printf("n =");
	int n = input_int();
	printf("\n");
	// init array
	int* a = (int*)malloc(sizeof(int*) * n);
	for (int* e = a; e != a + n; ++e) {
		*e = input_int();
	}
	printf("input special number s : \n");
	printf("s =");
	int s = input_int();
	// delete elements 5 0 1 2 3 4 2
	for (int i = 0, true_i = 0; i != n; ++i, ++true_i) {
		if (true_i % s == 0) {
			memmove(a + i, a + i + 1, (n - i - 1) * sizeof(int));
			--n; --i;
		}
	}
	// swap pairs
	for (int i = 0; i < n; i += 2) {
		int temp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = temp;
	}
	printf("result : \n");
	for (int* e = a; e != a + n; ++e) {
		printf("\t%d\n", *e);
	}
}