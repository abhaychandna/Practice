ll splits()
{
	ll ans = 0;

	ll n;
	cin >> n;
	vector<ll> v(n); 
	fo(i, n)cin >> v[i];
	
	ans += v[0];
	for (int i = 1; i < n; i++)
		ans += abs(v[i]);

	return ans;
}