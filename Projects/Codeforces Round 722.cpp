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

vl dfs(ll node, vl &vis, vvl &adj, vvl &lr) {
	vis[node] = 1;
	vvl v;
	vl temp(4);
	for (auto child : adj[node]) {
		if (vis[child] == false) {
			temp = (dfs(child, vis, adj, lr));
			v.pb(temp);
		}
	}

	if (v.size() == 0) {
		temp[0] = lr[node][0];
		temp[1] = lr[node][1];
		temp[2] = 0;
		temp[3] = 0;
		return temp;
	}
	
	vl ans(4);
	ans[0] = lr[node][0];
	ans[1] = lr[node][1];
	
	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
		ll x = 0;
		temp = v[i];
		x = abs(lr[node][0] - temp[0]) + temp[2];
		x = max(x, abs(lr[node][0] - temp[1]) + temp[3]);
		sum += x;
	}
	ans[2] = sum;

	sum = 0;
	for (int i = 0; i < v.size(); i++) {
		ll x = 0;
		temp = v[i];
		x = abs(lr[node][1] - temp[0]) + temp[2];
		x = max(x, abs(lr[node][1] - temp[1]) + temp[3]);
		sum += x;
	}
	ans[3] = sum;

	return ans;
}


ll solve()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vvl lr(n+1,vl(2));
	vl vis(n + 1);
	fo(i, n) {
		ll a, b;
		cin >> a >> b;
		lr[i + 1][0] = a;
		lr[i + 1][1] = b;
	}
	vvl adj(n + 1);
	fo(i, n - 1) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	ll root = 1;// change this 

	auto k = dfs(root, vis, adj, lr);
	ans = max(k[2], k[3]);
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
		ans = solve();
		cout << ans << '\n';
	}
}