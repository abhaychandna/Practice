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

#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>> 
#define vvl vector<vector<long long int>>
#define pi pair<int,int>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fon(i,start,end) for(int i=start;i<end;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;
int sz = 100007;
vl dp(sz);
ll solve()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vl v(n);
	map<ll, ll> mp;
	fo(i, n) {
		cin >> v[i];
		mp[v[i]]++;
	}

	for (auto it : mp) {
		ll x = it.first, y = it.second;
		
		y--;
		int j = 2;
		while (y> 0) {
			ans += (dp[j++] * y);
			y--;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (ll i = 2; i < dp.size(); i++) {
		dp[i] = (i * (i - 1)) / 2;
	}

	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = solve();
		//cout << ans << '\n';
	}
}