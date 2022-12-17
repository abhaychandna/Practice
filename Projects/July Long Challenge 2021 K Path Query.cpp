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

int getLCA(int a, int b, vl & dep, vvl & LCA) {

	if (dep[b] < dep[a])swap(a, b);

	int d = dep[b] - dep[a];
	while (d > 0) {
		int jump = log2(d);
		b = LCA[b][jump];
		d -= 1 << jump; //jump power 2
	}

	if (a == b)return a;

	for (int i = LCA[0].size() - 1; i >= 0; i--) {
		if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
			a = LCA[a][i],b=LCA[b][i];
	}

	return LCA[a][0];//parent of a
}

int getDist(int a, int b, vl & dep, vvl & LCA) {
	//if (dep[a] < dep[b])swap(a, b);
	return  dep[a] + dep[b] - (2LL * dep[getLCA(a, b, dep, LCA)]);
}

void setDepthDfs(int node, int par, int lvl, vl & dep, vvl & adj, vvl & LCA) {

	dep[node] = lvl;
	LCA[node][0] = par;

	for (auto child : adj[node])
		if (child != par)setDepthDfs(child, node, lvl + 1, dep, adj, LCA);
	return;
}

void initLCA(vl & dep, vvl & adj, vvl & LCA) {
	int n = adj.size(); // sizeof adj is n+1
	dep.resize(n);
	LCA.resize(n, vl(log2(n) + 5, -1));

	setDepthDfs(1, -1, 0, dep, adj, LCA);

	for (int i = 1; i < LCA[0].size(); i++) {
		for (int j = 1; j < LCA.size(); j++) {
			if (LCA[j][i - 1] != -1) {
				int par = LCA[j][i - 1];
				LCA[j][i] = LCA[par][i - 1];
			}
		}
	}
}

void dfsTime(int node, int par, int &time, vl& intime, vl& outtime, vvl &adj) {

	intime[node] = time++;
	for(auto child:adj[node])
		if (child != par)dfsTime(child, node, time, intime, outtime, adj);

	outtime[node] = time++;

}

bool findNotAnces(int a, int b, vl &intime, vl &outtime) {
	//if (intime[a] < intime[b])swap(a, b);
	if (intime[b]<intime[a] && outtime[b] > outtime[a])return true;
	if (intime[a]<intime[b] && outtime[a] > outtime[b])return true;
	return false;
}

ll Ynot()
{
	ll ans = 0;

	ll n;
	cin >> n;
	vvl adj(n + 1);
	fo(i, n - 1) {
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	vl dep;
	vvl LCA;
	initLCA(dep, adj, LCA);

	vl intime(n + 1), outtime(n + 1);
	int time = 1;
	dfsTime(1,-1,time,intime,outtime,adj);

	ll q;
	cin >> q;
	while (q--) {

		ll k;
		cin >> k;
		vl v(k);
		string s = "YES";
		vector<pair<ll, ll>> p;
		fo(i, k)cin >> v[i];
		fo(i, k)p.pb({ dep[v[i]],v[i] });
		sort(p.rbegin(), p.rend());
		fo(i, k)v[i] = p[i].second;

		int i = 1;
		while (i<k&& findNotAnces(v[i-1], v[i],intime,outtime))
			i++;
		
		if (i != k) {
			ll n2 = v[i];
			ll n1 = v[0];
			ll d = getDist(n1, n2, dep, LCA);

			fo(i, k) {
				ll x = v[i];
				if ( (getDist(x, n1, dep, LCA) + getDist(x, n2, dep, LCA)) != d)
					s = "NO";
			}
		}
		cout << s << '\n';
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
		ans = Ynot();
		//cout << ans << '\n';
	}
}