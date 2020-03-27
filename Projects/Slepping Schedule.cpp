#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
//#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, h, l, r;
	cin >> n >> h >> l >> r;

	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	const int x = 100;const int y = 100; // chang values 
	int dp[x][y];

	memset(dp, 0xc0, sizeof(dp));
	dp[0][0] = 0;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < h; j++)
		{
			int nt;
			
			nt = (j + a[i] - 1) % h;
			dp[i + 1][nt] = max(dp[i + 1][nt], dp[i][j] + (l<=nt&&nt<=r));

			nt = (j + a[i]) % h;
			dp[i + 1][nt] = max(dp[i + 1][nt], dp[i][j] + (l <= nt && nt <= r));
		}
	}
	int mx = 0;
	for (int i = 0; i < h; i++)mx = max(dp[n][i], mx);
	cout << mx << endl;

}