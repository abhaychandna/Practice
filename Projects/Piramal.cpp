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

ll INF = 1e15-1;

void fill(vvl & x, vvl v,vector<pair<int,int>> steps, int ci, int cj) {
	
	if (v[ci][cj] == 1)x[ci][cj] = 0;
	int n = v.size(), m = v[0].size();
	int is = ci, js = cj;
	int ie=n,istep=1, je=m,jstep=1;
	if (is != 0)ie = -1, istep = -1;
	if (js != 0)je = -1, jstep = -1;


	for (int i = is; i != ie; i+=istep) {
		for (int j = js; j != je; j+=jstep) {
			if (v[i][j] == 1)x[i][j] = 0;
			else {
				for (auto step : steps) {
					int a = i + step.first, b = j + step.second;
					if (a < n && b < m && a >= 0 && b >= 0) {
						x[i][j] = min(x[i][j], x[a][b] + 1);
					}
				}
			}
		}
	}

	fo(i, n) {
		fo(j, m)cout << x[i][j];
		cout << '\n';
	}
	return;
}

ll solve()
{
	ll ans = 0;
	int n;
	cin >> n;
	int m = n;
	vvl v(n,vl(n));
	
	fo(i, n) {
		string s;
		cin >> s;
		fo(j, n)v[i][j] = s[j]-'0';
	}
	vvl tplt(n, vl(n,INF));
	vvl tprt=tplt, btlt = tplt, btrt = tplt;
	vvl lt = tplt;
	if (v[0][0] == 1)tplt[0][0] = 0;
	if (v[0][0] == 1)tplt[0][0] = 0;
	if (v[0][0] == 1)tplt[0][0] = 0;
	if (v[0][0] == 1)tplt[0][0] = 0;
	
	fill(tplt, v, { {-1,-1},{-1,0}, {0,-1} }, 0,0);
	fill(tprt, v, { {-1,1},{0,1}, {-1,0} }, 0,m-1);
	fill(btlt, v, { {1,-1},{1,0}, {0,-1} }, n-1,0);
	fill(btrt, v, { {1,1},{1,0}, {0,1} },n-1,m-1);

	
	for (int i = 0; i < n; i++) {
		ll x = INF;
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1)x = 0;
			lt[i][j] = x;
			x = min(x + 1, INF);
		}
	}

	for (int i = n-1; i >=0; i++) {
		ll x = INF;
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1)x = 0;
			lt[i][j] = x;
			x = min(x + 1, INF);
		}
	}
	for (int i = 0; i < n; i++) {
		ll x = INF;
		for (int j = n-1; j >=0; j--) {
			if (v[i][j] == 1)x = 0;
			lt[i][j] = x;
			x = min(x + 1, INF);
		}
	}
	for (int i = n-1; i>=0; i--) {
		ll x = INF;
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1)x = 0;
			lt[i][j] = x;
			x = min(x + 1, INF);
		}
	}
	for (int i = 0; i < n; i++) {
		ll x = INF;
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1)x = 0;
			lt[i][j] = x;
			x = min(x + 1, INF);
		}
	}


	/*
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			if (v[i][j] == 0)continue;
			int r;	
			r = min({ lt[i][j], rt[i][j], tp[i][j], bt[i][j], tplt[i][j], tprt[i][j], btrt[i][j], btlt[i][j] });
			ans += r;

		}
	}

	*/
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
		ans = solve();
		cout << ans << '\n';
	}
}