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
ll n,k;
vvl dp;
vl v;

map<int, map<int, int>> mp;

ll recur(int i, int b) {

	if (b > k)return -1;
	if (i == n && b == (k-1)) {
		ll sum = 0;
		for (int i = 0; i < k; i++) {
			sum += mp[i].size();
			if (mp[i].size() == 0)return -1;
		}
		return sum;
	}
	if (i==n)return -1;
	if (b == k)return -1;
	
	if (dp[i][b] != -1)return dp[i][b];

	mp[b][v[i]]++;
	ll x = recur(i + 1, b);
	mp[b][v[i]]--;
	if (mp[b][v[i]] == 0)mp[b].erase(v[i]);
	mp[b + 1][v[i]]++;
	ll y = recur(i + 1, b + 1);
	mp[b + 1][v[i]]--;
	if (mp[b+1][v[i]] == 0)mp[b+1].erase(v[i]);

	dp[i][b] = max(x, y);
	return dp[i][b];

}

ll Ynot()
{
	ll ans = 0;
	
	cin >> n >> k;
	v.resize(n);
	fo(i, n)cin >> v[i];
	dp.resize(n);
	fo(i, n)dp[i].resize(k);
	fo(i, n)fo(j, k)dp[i][j] = -1;
	map<int, int> temp_mp;
	fo(i, k)mp[i] = temp_mp;
	
	ans = recur(0, 0);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		cout << ans << '\n';
	}
}