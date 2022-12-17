#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main()
{
	int x;
	scanf("%d", &x);
	int pw = 1;
	int ans = x % 10;
	x /= 10;
	while (x)
	{
		int dig = x % 10;
		ans += (pow(2,pw)) * dig;
		x /= 10;
		pw++;
	}
	printf("%d",ans);
	return 0;
}