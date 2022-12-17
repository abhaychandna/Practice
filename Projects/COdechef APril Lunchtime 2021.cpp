#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>

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
#define fot(i,start,end) for(int i=start;i<end;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

int p = -1;

void bfs(int node, int level, vvi &adj, vi &vis, vvi &distance) {
	if (vis[node] == true)return;
	vis[node] = true;
	distance[p][node] = level;
	for (auto x : adj[node]) {
		if (vis[x] == false)
			bfs(x, level + 1, adj, vis, distance);
	}
}

ll solve()
{
	ll ans = 0;
	ll n,m,b;
	cin >> n >> m >> b;
	vvi v(n, vi(m));
	fo(i, n) 
		fo(j, m)
			cin >> v[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < m; k++) {
				for (int l = k + 1; l < m; l++) {

					int sum = v[i][k] + v[i][l] + v[j][k] + v[j][l];
					if (sum == b)ans++;

				}
			}
		}
	}

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