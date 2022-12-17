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

void solve(vl &odd, ll num, ll len, vector<pair<ll,ll>> &q, vl &ln, vl &ans) {

	ll cur = ans.size() + odd.size() + len;
	int i = 0;
	while (i < odd.size())q.pb({ cur++, odd[i++] });
	i = 0;
	while (i < (len/2))q.pb({ cur++, num }),i++;
	

	ln.pb(2*(odd.size() + len));
	//*pre = *pre + 2 * (odd.size() + len);
	fo(t, 2) {
		fo(j, odd.size())ans.pb(odd[j]);
		fo(j, len)ans.pb(num);
	}
}

ll Ynot()
{
	vl ans;
	ll n;
	cin >> n;
	vl v(n);
	map<ll, ll> mp;
	fo(i, n) {
		cin >> v[i];
		mp[v[i]]++;
	}
	if (n % 2) {
		cout << -1 << '\n';
		return -1;
	}
	for (auto x : mp)if (x.second % 2) {
		cout << -1 << '\n';
		return -1;
	}
	int i = 0, j = 0;
	vector<pair<ll,ll>> k;
	int kid = 0;

	while (i < n) {
		int cnt = 1, num = v[i];
		i++;
		while (i < n && v[i] == v[i - 1])i++,cnt++;
		k.pb({ num,cnt });
	}

	vl ln;
	vector<pl> q;
	ll pre = 0;

	while (kid < k.size() && k[kid].second % 2 == 0) {
		ln.pb(k[kid].second);
		fo(j, k[kid].second)ans.pb(k[kid].first);
		pre += k[kid].second;
		kid++;
	}
	vl odd;
	if (kid < k.size()) {
		
		/*odd.pb(k[kid].first);
		if (kid < k.size() && k[kid].second > 1) {
			ln.pb(k[kid].second - 1);
			pre += k[kid].second-1;
			fo(j, k[kid].second - 1)ans.pb(k[kid].first);
			k[kid].second = 1;
			kid++;
		}*/

		while (kid < k.size()) {
			if (k[kid].second == 1) {
				odd.pb(k[kid].first);
				kid++;
				continue;
			}
			
			if (k[kid].second % 2 == 0) {
				solve(odd, k[kid].first, k[kid].second, q, ln, ans);
				
				
				
				reverse(odd.begin(), odd.end());
			}
			else {
				solve(odd, k[kid].first, k[kid].second-1, q, ln, ans);
				reverse(odd.begin(), odd.end());
				odd.push_back(k[kid].first);
			}
			kid++;
		}
	}

	/*
	fo(i, ans.size())cout << ans[i] << " ";
	cout << '\n';
	fo(i, odd.size())cout << odd[i] << " ";
	cout << '\n';
	*/
	ll half = odd.size() / 2;
	for (int i = 0; i < half; i++) {
		if (odd[i] != odd[i + half]) {
			
			
			ln.pb(2 * (odd.size()/2));
			


			ll cur = ans.size() + (odd.size()/2);
			int i = 0;
			while (i < (odd.size()/2))q.pb({ cur++, odd[i++] });
			i = 0;
			

			fo(j, (odd.size() / 2))ans.pb(odd[j]);
			fo(j, (odd.size() / 2))ans.pb(odd[j]);
			
			reverse(odd.begin(), odd.begin() + half);
			for (int j = 0; j < half; j++) {
				if (odd[i] != odd[i + half]) {

					cout << -1 << '\n';
					return -1;
				}
			}
		}
	}
	
	cout << q.size()<<'\n';
	fo(j, q.size())cout << q[j].first << " " << q[j].second << '\n';

	ll r = ln.size();
	if (odd.size() > 0)r++;
	cout << r<<'\n';
	fo(j, ln.size())cout << ln[j] << " ";
	if (odd.size() > 0) {
		cout << odd.size() << " ";
	}
	cout << '\n';

	return -2;
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