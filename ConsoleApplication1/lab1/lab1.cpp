#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>

// input a single number
double input_double() {
	double res;
	printf("\t");
	scanf("%lf", &res);
	return res;
}

int main() {
	printf("y = a^x +/- m\n");
	printf("a =");
	double a = input_double();
	printf("x =");
	double x = input_double();
	printf("m =");
	double m = input_double();
	double lib_res = pow(a, x);
	double curr_res = 0;
	double curr_f = 1;
	for (int deg = 0; abs(curr_res - lib_res) > m; ++deg) {
		curr_res += curr_f *= deg == 0 ? 1 : x * log(a) / deg;
	}
	printf("%lf ^ %lf = %lf +/- %lf. lib powf() result : %lf", a, x, curr_res, m, lib_res);
}