#include<stdio.h>
#include<string.h>
void main()
{
	int n;
	scanf("%d", &n);

	int t[2];
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);

	char c[3];

	int a = 0, s = 0;
	for (int i = 0; i < n; i++)
	{

		a = t[i] % 6;

		if (a != 0)
		{
			if (t[i] % 12 < 7 && t[i] % 12 > 0)
			{
				s = ((t[i] - a) + 12 - (a - 1));
			}

			else
			{
				s = ((t[i] + (6 - a) - 12 + (6 - (a - 1))));
			}


			if (a == 1 || a == 0)
			{
				c[0] = 'W'; c[1] = 'S';
			}
			else if (a == 2 || a == 5)
			{
				c[0] = 'M'; c[1] = 'S';
			}
			else if (a == 3 || a == 4)
			{
				c[0] = 'A'; c[1] = 'S';
			}
		}

		else
		{
			if (t[i] % 12 == 0)
				s = t[i] - 12 + 1;
			else
				s = t[i] + 1;
		}

		printf("%d %s\n", s, c);
	}
}