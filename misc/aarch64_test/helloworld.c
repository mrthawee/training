#include <stdio.h>

float sum_f(float a, float b) {
	return a + b;
}

double sum_d(double a, double b) {
	return a + b;
}

int main(void) {
	printf("hellow world\n");

	double x = 5.5;
	double y = 3.3;
	double z;
	z = sum_d(x, y);
	printf("z = %f\n", z);

	float a = 1.1;
	float b = 2.3;
	float c;
	c = sum_f(a, b);
	printf("c = %f\n", c);

	return 0;
}
