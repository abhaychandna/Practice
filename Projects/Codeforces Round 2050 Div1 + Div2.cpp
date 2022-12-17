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
	//ll ans = 0;

	ll n, m;
	cin >> n >> m;
	vvl v2(n, vl(m));
	
	//vvl vis = v;

	fo(i, n) {
		fo(j, m) {
			cin >> v2[i][j];
		}
		sort(v2[i].begin(), v2[i].end());
	}

	vvl v = v2;
	vector<pair<ll, ll>> se(n);

	fo(i, n)se[i] = { 0,m - 1 };

	vl mn(m);
	//vector<pair<ll, ll>> pr(n);
	//vvl ans2(n, vl(m));
	vvl ans(n, vl(m));
	fo(r, m) {
		ll k = se[0].first;
		ll j = 0;
		fo(i, n) {
			ll x = se[i].first;
			if (v[i][x] < v[j][k]) {
				j = i;
				k = se[i].first;
			}
		}

		fo(i, n) {
			if (i == k) {
				ll x = se[j].first;
				ans[i][r] = v[j][x];
				//cout << v[i][x] << " ";
				se[i].first++;
			}
			else {
				ll x = se[i].second;
				ans[i][r] = v[i][x];
				//cout << v[i][x]<<" ";
				se[i].second--;
			}
		}
		//cout << '\n';
	}

	fo(i,n) {
		fo(j,m) {
			cout << ans[i][j]<<" ";
		}
		cout << '\n';
	}

	/*
	fo(i, n) {
		ll k = 0;
		for (ll j = 1; j < n;j++) {
			if (v[j][i] < v[k][i]) k = j;
		}
		mn[i] = v[k][i];
		pr[i] = { k,1 };
		vis[]
		
	}
	sort(mn.begin(), mn.end());

	fo(i)
	*/
	return 0;
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