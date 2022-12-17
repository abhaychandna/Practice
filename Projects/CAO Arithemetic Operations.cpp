#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	
	if (argc != 3)
	{
		printf("2 numbers not found in input");
		return 0;
	}
	
	int ans;
	printf("Two numbers are %d %d\n", atoi(argv[1]), atoi(argv[2]));
	ans = atoi(argv[1]) + atoi(argv[2]);
	printf("Add - %d\n", ans);
	ans = atoi(argv[1]) - atoi(argv[2]);
	printf("Subtract - %d\n", ans);
	ans = atoi(argv[1]) * atoi(argv[2]);
	printf("Multiply - %d\n", ans);
	ans = atoi(argv[1]) / atoi(argv[2]);
	printf("Divide - %d\n", ans);
	return 0;
}