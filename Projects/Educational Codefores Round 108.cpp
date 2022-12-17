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
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define fos(i,start,end,step) for(int i=start;i<end;i+=step)

using namespace std;

ll solve()
{
	ll ans = 0;
	ll n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	vi u(n);
	fo(i, n)cin >> u[i];
	fo(i, n) {
		ll k;
		cin >> k;
		v[u[i]].push_back(k);
	}
	ll mx = -1;
	for (int i = 1; i < v.size();i++) {
		mx = max(mx, (ll) v[i].size());
		sort(v[i].rbegin(), v[i].rend());
		for (int j = 1; j < v[i].size(); j++) {
			v[i][j] += v[i][j - 1];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		ans = 0;
		for (int j = 1; j < v.size(); j++) {
			if (v[j].size() > 0 && v[j].size()>=i)
			{
				ll idx = -1;
				if (v[j].size() % i == 0)idx = v[j].size() - 1;
				else {
					ll x = v[j].size() / i;
					x *= i;
					idx = x - 1;
				}

				ans += v[j][idx];
			}
		}
		cout << ans << " ";
	}
	cout << '\n';
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
		//cout << ans << '\n';
	}
}