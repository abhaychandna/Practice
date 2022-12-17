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
vl tw;
vl fact;
map<ll, ll> mp;

ll Ynot()
{
	ll ans = 0;
	ll n, x;
	cin >> n;
	
	vvl adj(n + 1);
	fo(i, n - 1) {
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	queue<pair<ll,ll>> q;
	vl vis(n + 1);
	ll clr = 0;
	vl wt(n + 1);
	ll ans2 = 0;

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			q.push({ i,clr });
			wt[i] = 1;
			vis[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			ll par = adj[i][0];
			if (vis[par] != 1)q.push({ par, !clr });
			vis[par] = 1;
			wt[par] = 1;
		}
	}
	ll gc = 0;
	while (!q.empty()) {
		pair<ll,ll> node = q.front();
		q.pop();
		ll x = node.first;
		ll y = node.second;
		if (y == 0) {
			ans += adj[x].size();
			wt[x] = adj[x].size();
			gc++;
		}
		if (y == 1) {
			ans2 += 1;
			wt[x] = 1;
		}for (auto child : adj[x]) {
			if (!vis[child]) {
				vis[child] = 1;
				q.push({ child,!y });
			}
		}
	}
	//assert(ans2 <= ans1);
	cout << gc << " ";
	ans += ans2; 
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		cout << wt[i] << " ";
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();
		//cout << ans << '\n';
	}
}