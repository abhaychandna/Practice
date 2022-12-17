ll cricket()
{
	ll n;
	cin >> n;
	
	vector<ll> runs = { 1,2,3,4,6 };
	vector<ll> dp(n+6);
	
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (auto run : runs) {
			if (i - run >= 0)dp[i] += dp[i - run]; 
		}
	}
	
	return dp[n];
}
