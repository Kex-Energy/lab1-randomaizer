

#include <stdio.h>
#include <math.h>
const int M = 524287, a = 389, b = 454;

int generate(int xi) 
{
	return (a * xi + b) % M;
}
int main()
{
	int xi, x_periodic, res_histogram[20];
	double ui;
	printf("Inter seed:");
	scanf_s("%d", &xi);

	for (int i = 0; i < 20; i++) res_histogram[i] = 0;

	x_periodic = generate(xi);
	xi = x_periodic;
	ui = (double)xi / (double)M;
	res_histogram[(int)floor(ui / 0.05)]++;

	for (int i = 0, period=1; i < 99999; i++, period++)
	{
		xi = generate(xi);
		ui = (double)xi / (double)M;
		res_histogram[(int)floor(ui / 0.05)]++;
		if (xi == x_periodic) {
			printf("%d ", period);
			period = 0;
		}
	}
	printf("\n");
	for (int i = 0; i < 20; i++) printf("%d ",res_histogram[i]);
	return 0;
}

