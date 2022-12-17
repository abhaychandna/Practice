#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main()
{
	int x;
	scanf("%d", &x);
	int pw = 1;
	int sz = 10;
	int ans[20];
	int i = 0;
	for (i = 0; x > 0; i++)
	{
		ans[i] = x % 2;
		x /= 2;
	}
	i--;
	while (i >= 0)
	{
		printf("%d", ans[i]);
		i--;
	}
	
	return 0;
}