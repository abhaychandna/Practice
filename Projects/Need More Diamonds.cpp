// O(n^2) TIme Complexity
#include<iostream> 
#include<vector>
using namespace std; 
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n),sum(n);
		cin >> v[0];
		sum[0] = v[0];

		for (int i = 1; i < n; i++)
		{
			cin >> v[i];
			sum[i] = v[i] + sum[i - 1];
		}
		vector<vector<float>> dp(n, vector<float>(n,0.0));
		int s = 0;

		for (int i = 0, j = 0; j < n; i++, j++)
		{
			if(i==j)
				dp[i][j] = v[i];
			else
			{
				float x = 0;
				
				if (i - 1 > -1)
					x = sum[j] - sum[i - 1];
				else
					x = sum[j];

				dp[i][j] = x - (dp[i + 1][j] + dp[i][j - 1]) / 2.0;
			}
			if (j == n - 1)
			{
				s++;
				i = -1;
				j = s-1;
			}
		}

		cout << dp[0][n-1] << endl;
	}
}