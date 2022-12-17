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

map<ll, ll> mp;
void init() {
	ll x = 2;
	while (x < 1e12) {
		mp[x - 1] = 1;
		x *= 2;
	}
}

ll sm(ll n) {
	if (n <= 0)return 0;
	return ((n) * (n + 1)) / 2;
}

ll Ynot()
{
	ll ans = 0;
	ll n;
	cin >> n;

	if (n == 1)ans = 0;
	if (n <= 0)ans = 0;

	//n = i;
	ans = 0;

	if (mp[n] == 1)n--;


	while (n > 1) {

		if (mp[n] == 1)n--;
		if (n == 1)break;
		if (n == 2 || n == 3) {
			ans += 3;
			break;
		}
		ll x = 0;
		for (ll i = 0; i < 35; i++) {
			ll r = 1LL << i;
			if (r > n)break;
			x = i;
		}
		x = 1LL << x;

		ll extra = n - x;
		
		ll f = (sm(n));
		f -= sm(extra);
		ans = ans + f;
		n = extra;

	}
	ans *= 2;
	return ans;
}

int main()
{
	init();
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