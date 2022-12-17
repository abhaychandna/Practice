#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main()
{
	float x;
	scanf("%f", &x);

	printf("Using 3f - %3f\n", x);
	printf("Using 3.0f - %3.0f\n", x);
	printf("Using 3.2f - %3.2f\n", x);
	printf("Using 3.9f - %3.9f\n", x);

	return 0;
}