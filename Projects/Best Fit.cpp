#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<process.h>
int main()
{
	int a[20], b[20], f[20], i, j, l = 9999, x, y, z;
	static int ba[20], pa[20];
	printf("Enter the no. of blocks\n");
	scanf("%d", &x);
	for (i = 1; i <= x; i++)
	{
		printf("Enter the size of %d Block: ", i);
		scanf("%d", &a[i]);
	}
	printf("Enter the no. of process\n");
	scanf("%d", &y);
	for (i = 1; i <= y; i++)
	{
		printf("Enter the size of %d process: ", i);
		scanf("%d", &b[i]);
	}

	for (i = 1; i <= y; i++)
	{
		for (j = 1; j <= x; j++)
		{
			if (ba[j] != 1)
			{
				z = a[j] - b[i];
				if (z >= 0)
					if (l > z)
					{
						pa[i] = j;
						l = z;
					}
			}
		}
		ba[pa[i]] = 1;
		
	}

	printf("\nProcess no.\tProcess size\tBlock no\tBlock size\tFragment");
	for (i = 1; i <= y && pa[i] != 0; i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, b[i], pa[i], a[pa[i]], f[i]);
	}
	return 0;
}