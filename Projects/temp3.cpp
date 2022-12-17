#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

vl dx = { -1, -2, 0, 0 };
vl dy = { 0, 0, -1 ,-2 };
vl f1 = { 1, 2, 0 , 0 };
vl f2 = { 0, 0 , 1, 2 };
ll r(ll i, ll j, ll a, ll b, vector<vector<vector<vector<int>>>> &dp) {
	if (i < 0 || i >= n || j < 0 || j >= m)return 0;
	if (dp[i][j][a][b] != -1)return dp[i][j][a][b];
	for (int i = 0; i < dx.size(); i++) {
		dp[i][j] += r(i - dx[i], j - dy[j], f1[i], f2[i]);
	}
	dp[i][j][1][0] = dp[i][j-1][1][0] + dp[i][j-1][0][1] + dp[i][j-1][0][2];

	dp[i][j][2][0] = dp[i][j-2][0][1] + dp[i][j-2][0][2];


	dp[i][j][0][1] = dp[i - 1][j][1][0] + dp[i - 1][j][2][0] + dp[i-1][j][0][1];

	dp[i][j][0][2] = dp[i - 2][j][1][0] + dp[i - 2][j][2][0];

	return dp[i][j][a][b];;
}

ll s(ll n, ll m) {
	vector<vector<vector<vector<int>>>> dp;
	
	
}

ll solve(vector<ll> a, vector<ll> b, long long n, ll k) {
		// Write your code here.
	vector< int> v;
	long long diff = 0;
	int p = -1e9;
	for (int i = 0; i < n; i++) {
		//v[i] = 2 * (b[i] - a[i]);
		if (b[i] > a[i]) {
			p = max(p, (int)b[i] - (int)a[i]);
			//x[2 * (b[i] - a[i])]++;
		}

		diff += a[i] - b[i];
	}
	if (diff >= k)return 0;
	if (p < 0)return -1;
	vector<int>x(2*p+1, 0);
	for (int i = 0; i < n; i++) {
		if (b[i] > a[i]) {
			x[2 * (b[i] - a[i])]++;
		}
	}

	//sort(v.rbegin(), v.rend());

	int i = x.size()-1;
	while (i >=0) {
		for (int j = 0; j < x[i]; j++)
			v.push_back(i);
		i--;
	}
	i = 0;
	while (i < v.size() && diff < k) {
		diff += v[i++];
	}
	if (diff >= k)return i;
	return -1;
	

}

ll Ynot()
{
	ll ans = -1;
	ll n, k;
	cin >> n >> k;
	vl a(n), b(n);
	fo(i, n)cin >> a[i];
	fo(i, n)cin >> b[i];
	ans = solve(a, b, n, k);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}