#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include <iomanip>
#include <sstream>

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

vector<string> dfs(string node, map<string,bool> &vis, map<string,vector<string>> &mp, map<string, bool> &alert, map<string, bool> & nlr,
	map<string, vector<string>> & par) {

	vis[node] = true;

	vector<string> res;
	for (auto child : mp[node]) {
		if (vis[child] == false) {
			auto x = dfs(child,vis,mp,alert,nlr,par);
			vis[child] = true;
			for (auto s : x)
				res.push_back(s);
		}
	}

	if (res.size() == 0 && alert[node] == true) {
		if (nlr[node] == true) {
			res.push_back(node);
		}
		for (auto x : par[node])
			nlr[x] = false;
		nlr[node] = false;
	}
	return res;


}

void solve(map<string,vector<string>>& mp, map<string, vector<string>>& par, string root) {

	ll t;
	cin >> t;
	while (t--) {

		map<string, bool> vis;
		for (auto x : mp)vis[x.first] = false;

		ll n;
		cin >> n;
		map<string, bool> alert,nlr;
		fo(i, n) {
			string s;
			cin >> s;
			alert[s] = true;
		}
		nlr = alert;

		auto x = dfs(root,vis,mp,alert, nlr, par);
		
		cout << x.size() << " ";
		for (int i = 0; i < x.size();i++) {
			cout << x[i];
			if(i+1<x.size())
				cout<<" ";
		}cout << '\n';
	}

}

ll Ynot()
{
	ll ans = 0;

	ll n;
	cin >> n;
	vvl adj(n+1);
	map<string, vector<string>> mp,par;
	map<string, int> in;

	fo(i, n) {
		string s;
		cin >> s;
		in[s] = 0;
		mp[s] = {};
	}

	ll m;
	cin >> m;
	fo(i, m) {
		string s;
		cin >> s;
		int id = s.find(',');

		string x = s.substr(0, id);
		string y = s.substr(id + 1, s.size() - x.size() - 1);
		mp[x].pb(y);
		par[y].pb(x);
		in[y]++;
	}

	string root;
	for (auto x : in)if (x.second == 0)root = x.first;
	
	solve(mp, par, root);

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
		//cout << ans << '\n';
	}
}