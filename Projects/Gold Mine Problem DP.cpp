#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMaxGold(int gold[][4], int m, int n)
{
	int g[4][4] = { (0,0) };
	

	for (int i = 0; i < n; i++)
		g[i][m - 1] = gold[i][m - 1];

	for (int j = m-2; j >= 0; j--)
	{
		for (int i = 0; i < n ; i++)
		{
			int a=0, b=0, c=0;
			
			if (j + 1 < n)
				a = g[i][j + 1];
			
			if (i - 1 > -1 && j + 1 < n)
				b = g[i - 1][j + 1];
		
			if (i + 1 < m && j + 1 < n)
				c = g[i + 1][j + 1];

			g[i][j] = gold[i][j] + max(a, max(b, c));
		}
	}

	int max = 0;
	for (int i = 0; i < m; i++)
	{
		if (max < g[i][0])
			max = g[i][0];
	}
	return max;
}

int main()
{
	int gold[4][4] = { {1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << getMaxGold(gold, m, n);
	return 0;
}