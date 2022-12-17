#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include<bitset>

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

ll num = -1;

void dfs(int node, vvl& adj, vl& vis, vl& k) {
	vis[node] = 1;
	k[node] = num;

	for (auto child : adj[node]) {
		if (vis[child] == 0) {
			dfs(child, adj, vis, k);
		}
	}
}

int bs(vector<int>& ids, int id) {

	int n = ids.size();
	if (n == 1)return 0;
	int x;

	int res = -1;
	int low = 0, high = n - 1;
	while (low < high) {
		int mid = (low + high) / 2;

		vector<int> temp;
		for (int i = low; i <= mid; i++)temp.pb(ids[i]);
		temp.pb(id);
		cout << "? " << temp.size() << " ";
		for (auto id : temp)cout << id << " ";
		cout << endl;
		cin >> x;
		if (x == -1)return -1;
		if (x == 1)low = mid + 1;
		else high = mid;
	}
	return low;

}

ll Ynot()
{
	ll ans = 0;
	ll n, q, x;
	cin >> n >> q;


	vvl adj(n + 1);
	vl vis(n + 1);
	vl k(n + 1);
	k[0] = 1;
	k[1] = 1;

	vector<int> ids = { 1 };
	for (int i = 2; i <= n; i++) {
		cout << "? " << ids.size()+1 << " ";// << i << " " << i + step << endl;
		for (auto id : ids)cout << id << " ";
		cout << i << " ";
		cout << endl;
		cin >> x;
		//q--;
		if (x == -1)return -1;
		if (x == 1) {
			ids.pb(i);
			k[i] = i;
		}
		else {
			
			int p = bs(ids, i);
			if (p == -1)return -1;
			k[i] = k[ids[p]];

			//adj[i].pb(i + step);
			//adj[i + step].pb(i);
		}
		
	}
	

	/*
	ll step = -1, t = 0;

	while (q) {
		step = pow(2, t);
		t++;
		ll oldq = q;
		for (ll i = 1; i <= n; i++) {
			if (i + step > n)break;
			if (q == 0)break;

			cout << "? 2 " << i << " " << i + step << endl;
			cin >> x;
			q--;

			if (x == -1)return -1;
			if (x == 2) {
				adj[i].pb(i + step);
				adj[i + step].pb(i);
			}
		}
		if (q == 0)break;
		if (q == oldq)break;
	}

	
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			num = i;
			dfs(i, adj, vis, k);
		}
	}
	*/
	cout << "! ";
	for (int i = 1; i <= n; i++)cout << k[i] << " ";
	cout << endl;
	cin >> x;
	if (x == -1)return -1;

	return ans;
}

int main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll ans = 0;
		ans = Ynot();

		if (ans == -1)break;
		//cout << ans << '\n';
	}
}