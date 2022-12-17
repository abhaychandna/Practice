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

/*
ll solve(vvl prs, vl v, ll n, ll k) {

	ll res = -1e9;
	for (auto x : prs) {
		ll i = x[0], j = x[1];

		ll sum = (i+1) * (j+1) - (k * (v[i] | v[j]));
		res = max(res, sum);
	}
	return res;
}
*/

ll Ynot()
{
	ll ans = -1e9;

	ll n, k;
	cin >> n >> k;
	vl v(n);
	vector<vector<ll>> prs;

	fo(i, n) {
		cin >> v[i];
		prs.push_back({ v[i],i });
	}

	set<vector<ll>> s;
	for (ll i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll x = i*j;
			ll y = k * (v[i - 1] | v[j - 1]);
			ll z = x - y;
			s.insert({ z,x,y,i,j });
		}
	}
	
	
	sort(prs.begin(), prs.end());
	/*
	vvl v2,v3;
	int start = max(0LL, n - 100),end = n-1;

	for (int i =start; i <= end; i++) {
		for (int j = i + 1; j <= end; j++) {
			v2.push_back({ prs[i][1], prs[j][1] });
		}
	}
	
	for (auto x : v2) {
		ll i = x[0], j = x[1];

		ll sum = (i + 1) * (j + 1) - (k * (v[i] | v[j]));
		ans = max(ans, sum);
	}

	//ans = max(ans, solve(v2, v, n, k));

	
	start = 0, end = min(n-1, 99LL);
	for (int i = start; i <= end; i++) {
		for (int j = i + 1; j <= end; j++) {
			v3.push_back({ prs[i][1], prs[j][1] });
		}
	}

	for (auto x : v3) {
		ll i = x[0], j = x[1];

		ll sum = (i + 1) * (j + 1) - (k * (v[i] | v[j]));
		ans = max(ans, sum);
	}
	*/
	//ans = max(ans, solve(v3, v, n, k));
	
	/*
	for (ll i = 1; i <= n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll x = i * j;
			s.insert({ x,i,j });
		}
	}
	*/
	
	
	for (auto x : s) {
		for (int i = 0; i < x.size(); i++)cout << x[i] << " ";
		cout << '\n';
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
		cout << ans << '\n';
	}
}