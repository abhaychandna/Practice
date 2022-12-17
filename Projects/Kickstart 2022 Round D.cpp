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

int dfs(int node, vvl&adj, vl &vis) {
	
	vis[node] = 1;
	int k = 0;
	for (auto child : adj[node]) {
		if (!vis[child])
			k = dfs(child, adj, vis);
	}
	return k + 1;
}

ll Ynot()
{
	ll ans = 0;
	ll n, m, k;
	cin >> n >> m >> k;
	vl in(n + 1), vis(n+1);
	vvl adj(n+1);
	while (m--) {
		ll x, y;
		cin >> x >> y;
		in[y]++;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n;i++) {
		if (in[i] == 0) {
			vis[i] = 1;
			ll cnt = dfs(i, adj, vis);
			ans = max(ans, min(cnt,k));
		}
	}
	ans = n - ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ll ans = Ynot();
		cout << "Case #" << i << ": " << ans << endl;
	}
}