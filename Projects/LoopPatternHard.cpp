// LoopPatternHard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void top(int n)
{
	for (int i = 1; i <= n; i++)
	{
		int rc = i;
		int s = n;
		for (int j = 2 * n - 1; j >= 1; j--)
		{
			if (j <= i - 1)
			{
				s++;
			}

			std::cout << s;

			if (rc > 1)
			{
				s--;
				rc--;
			}
		}

		std::cout << "\n";
	}
}
void bottom(int n)
{
	int k = n - 2;
	for (int i = 2; i <= n; i++)
	{
		int rc = 1;
		int s = n;
		bool f = true;

		for (int j = 2 * n - 1; j >= 1; j--)
		{
			if (j <= k)
			{
				s++;
				f = false;
			}

			std::cout << s;

			if (s > i&& f)
			{
				s--;
				f = true;
			}
		}
		k--;
		std::cout << "\n";
	}
}
int main()
{
	int n;
	std::cin >> n;

	top(n);
	bottom(n);
}


